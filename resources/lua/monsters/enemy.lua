
require "player"
require 'skills.attack'


Enemy = {}
Enemy.__index = Enemy

local enemySkills = {
    attack = attack
}

function Enemy:new (o)
    local cls = o or {}
    setmetatable(cls, Enemy)

    cls.name = ""
    cls.hp = 0
    cls.stamina = 0
    cls.experience = 0
    cls.level = 0
    cls.player = PlayerBase:new(nil)

    cls.player.PrimaryAttributes.Intelligence:setValue(0)
    cls.player.PrimaryAttributes.Strength:setValue(0)
    cls.player.PrimaryAttributes.Dexterity:setValue(0)
    cls.player.PrimaryAttributes.Vitality:setValue(0)

    return cls
end

function Enemy:setPrimaryWeapon(weapon)
    self.primary_weapon = weapon
end

function Enemy:getPrimaryWeapon()
    return self.primary_weapon
end

function Enemy:listSkills()
    return enemySkills
end

function Enemy:chooseNextSkill(enemy_player)
    enemySkills["attack"](self, self.primary_weapon, enemy_player)
end

function Enemy:attack(enemy_player)
    attack(self, self.primary_weapon, enemy_player)
end

function Enemy:getExperience()
    if self.hp <= 0 then
        return self.level * self.experience
    end
    return 0
end
