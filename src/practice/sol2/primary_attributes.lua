
require "strength"
require "dexterity"
require "vitality"

PrimaryAttributeList = {}
PrimaryAttributeList.__index = PrimaryAttributeList

function PrimaryAttributeList:new ()
    local cls = {}

    setmetatable(cls, PrimaryAttributeList)

    cls.Strength = Strength:new()
    cls.Dexterity = Dexterity:new()
    cls.Vitality = Vitality:new()

    return cls
end
