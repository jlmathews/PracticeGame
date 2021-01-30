
require "primary_attribute"

Intelligence = {}
Intelligence.__index = Intelligence

function Intelligence:new ()
    local cls = {}
    setmetatable(cls, Intelligence)
    setmetatable(Intelligence, {__index = PrimaryAttribute})

    cls:setName("Intelligence")
    cls:setDescription("Intelligence description")
    cls:setValue(0)

    return cls
end
