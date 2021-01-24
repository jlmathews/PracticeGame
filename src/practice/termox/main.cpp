#include "spdlog/spdlog.h"
#include <termox/termox.hpp>
#include <termox/painter/palette/dawn_bringer16.hpp>

using namespace ox;
using namespace ox::pipe;
using ox::Color;

class ThinButton : public Button
{
   public:
    ThinButton(Glyph_string title) : Button{std::move(title)}
    {
        *this | fixed_height(1) | bg(Color::Red);
    }
};

struct CreatePlayerPane : layout::Vertical<>
{
    using Period_t = std::chrono::milliseconds;

    HLabel& title = this->make_child<HLabel>(L"Create Player Menu");

    CreatePlayerPane()
    {
        *this | fixed_width(16);
        *this | bordered() | bold_walls() | bg(Color::Light_blue) |
            fg(Color::Blue);
    }
};

struct LoadPlayerPane : layout::Vertical<>
{
    using Period_t = std::chrono::milliseconds;

    HLabel& title = this->make_child<HLabel>(L"Load Player Menu");

    LoadPlayerPane()
    {
        *this | fixed_width(16);
        *this | bordered() | bold_walls() | bg(Color::Light_blue) |
            fg(Color::Blue);
    }
};

struct SettingsPane : layout::Vertical<>
{
    using Period_t = std::chrono::milliseconds;

    HLabel& title = this->make_child<HLabel>(L"Settings Menu");
    ThinButton& setting1 = this->make_child<ThinButton>(L"Settings 1");
    ThinButton& setting2 = this->make_child<ThinButton>(L"Settings 2");
    Labeled_number_edit<>& counter =
        this->make_child<Labeled_number_edit<>>(L"Counter: ", 0);

    SettingsPane()
    {
        // setting1.pressed.connect([this] { this->add_widget(); });
        setting1.pressed.connect([this] {  });

        counter | fixed_height(1);

        *this | fixed_width(16);
        *this | bordered() | bold_walls() | bg(Color::Light_blue) |
            fg(Color::Blue);
    }

    protected:
        auto mouse_press_event(Mouse const& m) -> bool override
        {
            if (m.button == Mouse::Button::Left)
                points_.push_back(m.local);
            this->enable_animation(FPS{10});
            // this->enable_animation(Period_t{100});
            this->update();  // post a paint event to *this
            return Widget::mouse_press_event(m);
        }

        auto paint_event() -> bool override
        {
            auto painter = Painter{*this};

            // Redraw points on the screen
            for (auto point : points_)
            {
                painter.put(L'X', point);
            }

            return Widget::paint_event();
        }

        auto timer_event() -> bool override
        {
            // Increment points one space down the screen
            for (auto& point : points_)
            {
                point.y += 1;
            }

            // Remove points that are off the screen
            points_.erase(std::remove_if(points_.begin(), points_.end(),
                [&](const Point& point) { 
                    return point.y >= this->height();
                }),
                points_.end());

            // Update counter with number of points
            counter.set_value(points_.size());

            this->update();
            return Widget::timer_event();
        }

    private:
        std::vector<Point> points_;
};

void EscapeCallback()
{
    spdlog::info("Escape Callback");
    System{}.exit();
}

/**
 *
 */
class MainMenu : public Menu_stack
{
    public:
        MainMenu(Glyph_string title) : Menu_stack{std::move(title)}
        {
            Shortcuts::add_shortcut(Key::Escape).connect([this] {
                System::terminal.set_palette(dawn_bringer16::palette);
                this->Menu_stack::goto_menu();
            });

            this->make_page<CreatePlayerPane>(L"New Player");
            this->make_page<LoadPlayerPane>(L"Load Player");
            this->make_page<SettingsPane>(L"Settings");
        }
};

class MainApp : public layout::Vertical<>
{
    public:
        using Titlebar = ox::Titlebar;

        Titlebar& title = this->make_child<Titlebar>("~ PGame ~");
        MainMenu& menu  = this->make_child<MainMenu>("Main Menu");

        MainApp() { this->focus_policy = Focus_policy::Direct; }

    protected:
        auto focus_in_event() -> bool override
        {
            System::set_focus(menu);
            return true;
        }
};

int main()
{
    spdlog::info("Practice TermOx.");

    System{}.run<MainApp>();

	return 0;
}