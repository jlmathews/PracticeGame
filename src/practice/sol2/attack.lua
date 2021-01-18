
data = {
    name = "attack",
    dmg = 10,
    speed = 1.2
}

bow = {
    name = "bow",
    min_dmg = 5,
    max_dmg = 10,
    speed = 1.5,
    crt_chance = 5,
    crt_dmg = 50
}

enemy = {
    name = "enemy1",
    hp = 250,
    stamina = 150,
    str = 5,
    dex = 4,
    vit = 6,
    level = 2,
    experience = 10
}


function enemy:new (o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

function enemy:getExperience()
    if self.hp <= 0 then
        return self.level * self.experience
    end
    return 0
end

enemy1 = enemy:new(nil)

club = {
    name = "club",
    min_dmg = 3,
    max_dmg = 7,
    speed = 1.0,
    crt_chance = 3,
    crt_dmg = 25
}

math.randomseed(500)

function dpa(weapon)
    return math.random(weapon.min_dmg, weapon.max_dmg)
end

function normal_damage(weapon)
    return dpa(weapon) * (1 - (weapon.crt_chance / 100))
end

function critical_damage(weapon)
    return dpa(weapon) * (weapon.crt_chance / 100) * weapon.crt_dmg
end

function final_damage(weapon)
    return normal_damage(weapon) + critical_damage(weapon)
end

function dps(weapon)
    return (final_damage(weapon) * weapon.speed)
end

function attack (player1, weapon1, player2)
    player2.hp = player2.hp - dps(weapon1)
end
