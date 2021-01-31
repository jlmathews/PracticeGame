
require "classes.rogue"


print("Create Rogue")
r = Rogue:new()

print(r.player.PrimaryAttributes.Intelligence:getName())
print(r.player.PrimaryAttributes.Intelligence:getDescription())
print(r.player.PrimaryAttributes.Intelligence:getValue())
print("----------------")
print(r.player.PrimaryAttributes.Strength:getName())
print(r.player.PrimaryAttributes.Strength:getDescription())
print(r.player.PrimaryAttributes.Strength:getValue())
print("----------------")
print(r.player.PrimaryAttributes.Dexterity:getName())
print(r.player.PrimaryAttributes.Dexterity:getDescription())
print(r.player.PrimaryAttributes.Dexterity:getValue())
print("----------------")
print(r.player.PrimaryAttributes.Vitality:getName())
print(r.player.PrimaryAttributes.Vitality:getDescription())
print(r.player.PrimaryAttributes.Vitality:getValue())
print("----------------")
