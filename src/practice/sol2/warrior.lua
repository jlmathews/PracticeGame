
require "player"

Warrior = {}
Warrior.__index = Warrior

function Warrior:new ()
    local cls = {}
    setmetatable(cls, Warrior)

    cls.name = "Warrior"
    cls.hp = 500
    cls.stamina = 200
    cls.player = PlayerBase:new(nil)

    cls.player.PrimaryAttributes.Intelligence:setValue(5)
    cls.player.PrimaryAttributes.Strength:setValue(20)
    cls.player.PrimaryAttributes.Dexterity:setValue(10)
    cls.player.PrimaryAttributes.Vitality:setValue(15)

    return cls
end

function Warrior:setPrimaryWeapon(weapon)
    self.primary_weapon = weapon
end

function Warrior:attack(enemy_player)
    attack (self, self.primary_weapon, enemy_player)
end
