
require "attributes.dexterity"
require "attributes.intelligence"
require "attributes.strength"
require "attributes.vitality"

PrimaryAttributeList = {}
PrimaryAttributeList.__index = PrimaryAttributeList

function PrimaryAttributeList:new ()
    local cls = {}

    setmetatable(cls, PrimaryAttributeList)

    cls.Strength = Strength:new()
    cls.Dexterity = Dexterity:new()
    cls.Vitality = Vitality:new()
    cls.Intelligence = Intelligence:new()

    return cls
end
