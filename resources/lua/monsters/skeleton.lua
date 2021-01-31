
require "monsters.enemy"
require "weapons.club"
require "utilities.inheritance"

Skeleton = inheritsFrom(Enemy)

function Skeleton:Setup()
    self.name = "Skeleton"
    self.hp = 250
    self.stamina = 250
    self.experience = 10
    self.level = 2
    self.player = PlayerBase:new(nil)

    self.player.PrimaryAttributes.Intelligence:setValue(3)
    self.player.PrimaryAttributes.Strength:setValue(6)
    self.player.PrimaryAttributes.Dexterity:setValue(5)
    self.player.PrimaryAttributes.Vitality:setValue(5)

    self:setPrimaryWeapon(club)
end
