
PrimaryAttribute = {}
PrimaryAttribute.__index = PrimaryAttribute

function PrimaryAttribute:new ()
    local cls = {}
    setmetatable(cls, PrimaryAttribute)

    cls.Name = "Default"
	cls.Description =  "Default description"
	cls.isPrimaryAttribute = true
    cls.Value = 0

    return cls
end

function PrimaryAttribute:getValue()
    return self.Value
end

function PrimaryAttribute:setValue(value)
    self.Value = value
end

function PrimaryAttribute:getName()
    return self.Name
end

function PrimaryAttribute:setName(value)
    self.Name = value
end

function PrimaryAttribute:getDescription()
    return self.Description
end

function PrimaryAttribute:setDescription(value)
    self.Description = value
end
