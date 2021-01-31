
require "player"
require "utilities.inheritance"

Mage = {}
Mage.__index = Mage

function Mage:new()
    local cls = {}
    setmetatable(cls, Mage)
    setmetatable(Mage, {__index = PlayerBase})

    cls.name = "Mage"
    cls.hp = 500
    cls.stamina = 200

    self.PrimaryAttributes = PrimaryAttributeList:new()

    cls.PrimaryAttributes.Intelligence:setValue(20)
    cls.PrimaryAttributes.Strength:setValue(15)
    cls.PrimaryAttributes.Dexterity:setValue(15)
    cls.PrimaryAttributes.Vitality:setValue(12)

    return cls
end
