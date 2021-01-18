
require "primary_attribute"

Vitality = {}
Vitality.__index = Vitality

function Vitality:new ()
    local cls = {}
    setmetatable(cls, Vitality)
    setmetatable(Vitality, {__index = PrimaryAttribute})

    cls:setName("Vitality")
    cls:setDescription("Vitality description")
    cls:setValue(0)

    return cls
end
