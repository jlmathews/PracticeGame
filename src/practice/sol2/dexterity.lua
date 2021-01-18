
require "primary_attribute"

Dexterity = {}
Dexterity.__index = Dexterity

function Dexterity:new ()
    local cls = {}
    setmetatable(cls, Dexterity)
    setmetatable(Dexterity, {__index = PrimaryAttribute})

    cls:setName("Dexterity")
    cls:setDescription("Dexterity description")
    cls:setValue(0)

    return cls
end
