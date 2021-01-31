
require "player"

Rogue = {}
Rogue.__index = Rogue

function Rogue:new()
    local cls = {}
    setmetatable(cls, Rogue)
    setmetatable(Rogue, {__index = PlayerBase})

    cls.name = "Rogue"
    cls.hp = 500
    cls.stamina = 200

    self.PrimaryAttributes = PrimaryAttributeList:new()

    cls.PrimaryAttributes.Intelligence:setValue(8)
    cls.PrimaryAttributes.Strength:setValue(10)
    cls.PrimaryAttributes.Dexterity:setValue(20)
    cls.PrimaryAttributes.Vitality:setValue(13)

    return cls
end
