
require "player"

Warrior = {}
Warrior.__index = Warrior

function Warrior:new()
    local cls = {}
    setmetatable(cls, Warrior)
    setmetatable(Warrior, {__index = PlayerBase})

    cls.name = "Warrior"
    cls.hp = 500
    cls.stamina = 200

    self.PrimaryAttributes = PrimaryAttributeList:new()

    cls.PrimaryAttributes.Intelligence:setValue(5)
    cls.PrimaryAttributes.Strength:setValue(20)
    cls.PrimaryAttributes.Dexterity:setValue(10)
    cls.PrimaryAttributes.Vitality:setValue(15)

    return cls
end
