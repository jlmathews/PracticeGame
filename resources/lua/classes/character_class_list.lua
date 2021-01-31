
require "classes.mage"
require "classes.rogue"
require "classes.warrior"

CharacterClassList = {}
CharacterClassList.__index = CharacterClassList

function CharacterClassList:new ()
    local cls = {}

    setmetatable(cls, CharacterClassList)

    cls.list = {}

    return cls
end

function CharacterClassList:AddCharacterType(character)
    table.insert(self.list, character)
end

function CharacterClassList:NumCharacterTypes()
    return #self.list
end

-- Create list of possible character classes
characterClassList = CharacterClassList:new()
characterClassList:AddCharacterType(Mage:new())
characterClassList:AddCharacterType(Rogue:new())
characterClassList:AddCharacterType(Warrior:new())

print("Size: ", characterClassList:NumCharacterTypes())

for key,value in ipairs(characterClassList.list) 
do
   print(key, value.name)
end
