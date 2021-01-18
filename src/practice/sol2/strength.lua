
require "primary_attribute"

Strength = {}
Strength.__index = Strength

function Strength:new ()
    local cls = {}
    setmetatable(cls, Strength)
    setmetatable(Strength, {__index = PrimaryAttribute})

    cls:setName("Strength")
    cls:setDescription("Strength description")
    cls:setValue(0)

    return cls
end
