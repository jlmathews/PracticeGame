
require "player"

Mage = {}
Mage.__index = Mage

function Mage:new ()
    local cls = {}
    setmetatable(cls, Mage)

    cls.name = "Mage"
    cls.hp = 500
    cls.stamina = 200
    cls.player = PlayerBase:new(nil)

    cls.player.PrimaryAttributes.Intelligence:setValue(20)
    cls.player.PrimaryAttributes.Strength:setValue(15)
    cls.player.PrimaryAttributes.Dexterity:setValue(15)
    cls.player.PrimaryAttributes.Vitality:setValue(12)

    return cls
end

function Mage:setPrimaryWeapon(weapon)
    self.primary_weapon = weapon
end

function Mage:attack(enemy_player)
    attack (self, self.primary_weapon, enemy_player)
end
