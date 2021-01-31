

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
