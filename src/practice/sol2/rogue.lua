
require "player"

Rogue = {}
Rogue.__index = Rogue

function Rogue:new ()
    local cls = {}
    setmetatable(cls, Rogue)

    cls.name = "Rogue"
    cls.hp = 500
    cls.stamina = 200
    cls.player = PlayerBase:new(nil)

    cls.player.PrimaryAttributes.Intelligence:setValue(8)
    cls.player.PrimaryAttributes.Strength:setValue(10)
    cls.player.PrimaryAttributes.Dexterity:setValue(20)
    cls.player.PrimaryAttributes.Vitality:setValue(13)

    return cls
end

function Rogue:setPrimaryWeapon(weapon)
    self.primary_weapon = weapon
end

function Rogue:attack(enemy_player)
    attack (self, self.primary_weapon, enemy_player)
end
