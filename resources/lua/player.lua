
require "attributes.primary_attributes"

PlayerBase = {}
PlayerBase.__index = PlayerBase

function PlayerBase:new ()
    local cls = {}

    setmetatable(cls, PlayerBase)

    cls.PrimaryAttributes = PrimaryAttributeList:new()

    return cls
end

function PlayerBase:setPrimaryWeapon(weapon)
    self.primary_weapon = weapon
end

function PlayerBase:getPrimaryWeapon()
    return self.primary_weapon
end

function PlayerBase:attack(enemy_player)
    attack(self, self.primary_weapon, enemy_player)
end
