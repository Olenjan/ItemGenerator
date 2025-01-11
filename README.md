# Description		

## General definitions

--- Fundementals

// User
Account - A persistent collection of data and privileges with unique login information
User - A logged in 'account' interacting with system-level services 

// Game
Game - An interactive environment with defined rules, states, objectives
Player - A 'User' who interacts with the 'game'
Game client - Software running on 'user(s)' device that the 'Player' is using to interact with the 'game'
Game server - Authoritative software system defining and controlling the 'game(s)' state, running on dedicated hardware or cloud infrastructure

// Game basics
Entity - Anything that exists as a distinct, independent, or self-contained unit. Physical or abstract
Position - 3D Spatial coordinate of an 'Entity'
State - The complete set of variable values/attributes/properties that describe an 'entity' at a given time. All 'entity(ies)' have 'Position'
Scene - A spatiotemporal arrangement of 'entity(ies)' and their relationships at a given time in euclidean space
Behavior - The pattern of Actions performed and state changes experienced by an Entity over time within a Scene
Behavior - The temporal evolution of an 'entity(s)' state and 'Action(s)' performed by it within a scene

// Gameplay
Game/Gameplay/core system - A set of rules, processes objectives that controls how a specific part of a 'game' works.
Mechanic - A functional component of a 'game system'
Gameplay - Emergent patterns of interaction between a 'player' and a set of 'game system(s)'
Content - Deliberately designed experience delivered through 'game systems'



--- Scene

// Space
Surface - Immutable structure within a 'scene' that has a physical boundary and visual representation.
Playspace - The total volume within 'scene' enclosed by 'surface(s)' where gameplay can occur

// Object
Object - A non-abstract 'entity' within a 'playspace' that cannot exist the 'playspace' within a scene. Is not a 'surface'

// Static object
Prop - An 'object' within 'playspace' that enhances visual detail and ambiance. Can have basic 'behavior'
Destructible - A temporary 'prop' that can be removed from the 'playspace' through interaction

// Dynamic objects
Actor - An autonomous 'object' that has controlled 'behavior' either by a 'player' or an 'AI'
Action - Any operation that can be performed by an 'Actor'
Action speed - base 'property' that defines a rate at which 'Action(s)' can be performed.	

// Area
Tileset - A collection of reusable 'surface(s)' and 'prop(s)' designed to be used together to construct consistent 'playspace'
Layout - A set of instructions defining how a 'tileset' is arranged. Either fixed, randomly or semi-random
Area - A 'playspace' built from a set of possible 'tileset(s)' and 'layout(s)'
Zone - A collection of connected 'Area(s)' sharing a progressing theme
World - A collection of interconnected 'zone(s)'



--- Gameplay layer

// Gameplay Area
Instance - A unique, isolated copy of an 'Area' with a specific 'layout' and a 'tileset'.
Environment - The immediate surroundings of the 'player' in an 'Instance', including nearby 'surface(s)' and 'prop(s)'

// Gameplay Character
Character - An 'Actor' controlled by a player or an AI
Player character - A 'Character' controlled by a 'player'
NPC - A 'Character' controlled by an AI that is friendly towards the 'player'
Enemy - A 'Character' controlled by an AI that is hostile towards the 'player'
Resource - A 'property' of a 'character' spent by doing certain 'action(s)' and regenerated by a 'Character'
Regeneration - A 'Property' that passively restored a 'Resource' per second for the 'Character'


// Gameplay basics
Rarity - An abstract classification that determines how uncommon and powerful something is. (Normal, Uncommon, Rare, Unique)
Item - An 'Object' or an 'Entity' that can be picked up, carried, dropped and possibly used by a 'Character'. Is of certain 'Rarity'
Property - A numeric value or flag that is one variable of a state for a 'mechanic' or a set of 'mechanic(s)' across 'game system(s)'
Modifier - additive or multiplicative value that changes one or more 'property(ies)'
Progression point - A value that can be spent to increase a permanently change 'Character(s)' 'Property(ies)'
Activity - An interaction with one or more 'game system(s)' that a 'Character' can participate in
Objective - A designed goal that requires completing one or more 'gameplay activity(ies)'
Problem - A complication or difficulty that reduces play experience and needs to be resolved by the 'player'
Reward - 'Item(s)' or 'Progression point(s)' that are obtained by completing an 'objective'

	// Gameplay item basics
	Itemization - The complete set of meaningful 'Equipment' choices available to a 'Character' to solve 'Problem(s)'
	Affix - A single 'Modifier' that is part of an item
	Item Type - A category of 'Item' that determines how it can be used
	Inventory - a Limited storage space for 'item(s)' currently being carried by a 'Character'
	Stash - A Persistent storage space for 'item(s)' permanently stored by a 'character' or an 'account'
	Ground item - an 'Item' that exists as an 'Object' within an 'instance'
	Inventory item - an 'Item' that exists as an 'Entity' within a 'Character(s)' 'Inventory' or 'Stash' 
	Equipment - An 'Inventory item' that can be worn or wielded by a 'Character' to provide benefits
	Equipment Type - A specific category of 'Equipment' that determines how it can be worn or wielded
	Equipment slot - A designated position where a single piece of 'equipment' of certain 'Equipment Type' can be put on a 'Character'
	Container - An 'Object' in an 'Instance' that can dispense 'Item(s)'
	Loot - 'Item(s)' that are obtained from defeated 'Enemy(s)', from 'Container(s)' or as a 'Reward'
	


	// Gameplay Properties
	Character property - a set of 'Property(ies)' of a 'Character'
	Equipment property - a unique set of 'Property(ies)' of an 'Equipment' of type
	Instance property - a set of 'Property(ies)' that affect an entire 'Instance' and all 'Enemy(s)' within it.
	Property tag - Label that categorizes the type of a 'property'


	// Progression ( Gameplay character power )
	Character class - Template that defines base values for 'property(ies)' of a 'Character'
	Character Power - A set of 'Character property(ies)' that represents the overall 'Combat' effectiveness of a 'Character'
	Passive Tree - A structured collection of permanent increases to 'property(ies)' that can be acquired by spending 'Progression point(s)' to increase 'Character Power'
	Level - A discrete rank that represents a 'Character's' overall progression and number of base 'Progression point(s)' they have obtained
	Experience - A value that measures a 'Character's' progress towards gaining a 'Level'. Percentage progress towards obtaining a 'Progression point'

	// Activity - Activity that has a reward
		// Core interaction systems - Low to medium reward - Well timed dodge, Killing difficult enemy
		Movement system - A 'game system' that governs how a 'Character' traverses the 'environment' in an 'instance'
		Combat system - A 'game system' that governs how 'Character(s)' engage in conflict with each other in an 'instance'
		
		// Core Item system - low to high reward - Having clean inventory, Looting or crafting a good item
		Inventory management system - A 'game system' that governs how 'Item(s)' are stored, organized, and handled by a 'Character'
		Loot system - A 'game system' that governs how 'loot' is generated
		Crafting system - A 'game system' that governs how 'Item(s)' are created or modified by a 'Player'

		// Gameplay power systems - Medium to high reward - Increasing character power is rewarding
		Leveling system - A 'game system' that governs how a 'Character' gains 'Experience', reaches new 'Level(s)', and receives 'progression point(s)' through gameplay activities
		Character class system - A 'game system' that gives a 'character' base 'Character power'
		Equipment system - A 'game system' that affects 'Character power' through 'Equipment'
		Passive tree system - A 'game system' that provides permanent increases to 'Character Power' through investment of 'Progression points' in the 'Passive tree'
		Challenge System - A 'game system' that affects 'Enemy' difficulty and rewards by modifying 'Instance property(ies)' 

		// Gameplay objective systems - low to medium reward - Finish a campaign or a long questchain
		Quest system - ...
		Campaign system - ...

		
		// Challange systems - medium to high reward - Killing a difficult boss
		Boss system - ...


	// Movement
	Movement - ...
	Movement speed - ...
	Dodge - ...
	...

	// Combat
	Combat - A state where 'Character(s)' engage in conflict with each other
	Target - An 'Actor', a 'prop' or a 'Position' that will receive the 'effect(s)' of an 'action'	
	Life - 'Resource' representing health of the 'Character' that results in death when reading zero
	Mana - 'Resource' that is required to perform certain 'Actions'. More powerful actions consume more of that 'Resource'
	Reserve - A portion of a 'Resource' that becomes unavailable for consumption while maintaining a specific 'Effect' or 'Passive Skill' active
	
		// (1) Basics definitions
		
			// Effect
			Effect Object - A temporary 'object' created by an 'Action' within an 'instance' and can affect 'Target(s)'
			Effect - A temporary or permanent change to one or more 'Property(ies)' of a 'Target(s)'
			Effect stack - A cumulative instance of an 'Effect' that can build up on a 'Target'
			Area of Effect - A "Character property" that affects the volume within the 'instance' where an 'Effect' or 'Effect Object' will affect all valid 'Target(s)'	
			Duration - A finite time period during which an 'Effect' or 'Effect Object' remains active
			
			
			// Damage
			Damage - A negative 'Effect' that reduces a 'Target(s)' 'Life' 'Resource'
			Damage Type - A 'Property tag' that determines how 'Damage' interacts with defensive 'Property(ies)'
			Damage over Time (DOT) - 'Damage' of a certain 'Damage type' that is applied repeatedly at fixed intervals over a 'Duration'
			Weapon - 'Equipment type' that enables 'Character' to perform certain types of damaging 'Action(s)'
			
			// Damage mitigation
			Heal - A positive 'Effect' that restores a 'Target(s)' 'Life' 'Resource'
			Defense - A 'Character Property' that reduces incoming 'Damage'
			Avoidance - A 'Character Property' that gives a chance to avoid incoming 'Damage'
			
			// Skill
			Skill - A predefined 'Action' that a 'Character' can perform, which may create 'Effect Object(s)' and/or apply 'Effect(s)' to 'Target(s)'. May consume a 'Mana'		
			Passive Skill - A permanent modification to one or more 'Character property(ies)' that does not require an 'Action' or consume 'Mana'. May 'Reserve(s)' a 'Resource(s)'
			Cooldown - A time period after using a 'Skill' during which it cannot be used again
			
			Skill Phase - A distinct time period during the performance of a 'Skill', consisting of 'Skill Windup', 'Skill Execute', and 'Skill Recovery'
			Skill Windup - Initial time period of a 'Skill Phase'
			Skill Execute - The moment a 'Character' attempts to make a 'Skill' connect with a 'Target'
			Skill Recovery - Final time period of a 'Skill Phase' after the 'Skill Execute' before another 'Skill' can be performed
				
			Projectile - An 'Effect Object' that travels in a defined direction through the 'environment' until it hits a valid 'Target' or maximum distance.
			Attack - A 'Skill' that deals direct 'Damage' to a 'Target' with a 'Weapon'. May consume a 'Mana'
			Attack Speed - Rate at which 'Attack(s)' can be performed. Reduces 'Skill phase' times.	
			
			Spell - A 'Skill' that creates either a 'Projectile(s)', 'Effect(s)' or 'Effect Object(s)' to 'heal' or deal 'damage'. Consumes 'Mana'
			Cast Speed - Rate at which 'Spell(s)' can be performed. Reduces 'Skill phase' times.
			
			Hit - When an 'Skill Execute' successfully connects with a 'Target'
			Miss - When an 'Skill Execute' fails to connect with a 'Target'

			Intensity - A percentage of base 'damage' applied as 'damage' from any given 'Skill' on hit 


		// (2) Derived definitions
 
			// Effect 2					
			Status Effect - A temporary 'Effect' that modifies a 'Character Property(ies)' or 'behavior'
			Ground Effect - An 'Effect Object' that persists in an 'instance' and can affect 'Target(s)' within its 'Area of Effect'	
			Buff - A Positive 'Status effect'
			Debuff - A Negative 'Status effect'
			Ailment - A 'Debuff' that partially disrupts for a certain 'Duration' caused by a repeatedly being dealt a specific 'Damage Type' or by specific 'Skill(s)'
			Impairment - A 'Debuff' that fully disrupts for a certain 'Duration' caused by reaching a threshold of 'Ailment' 'Effect stack(s)' or triggered by specific 'Skill(s)'
			
			// Damage 2		
				// Damage 2 - damage
				Accuracy - A 'Character Property' that affects chance of 'Hit' with an 'Attack'
					
				// Damage 2 - Damage type
				Physical Damage 	- A 'Damage Type' caused by physical means
				Elemental Damage 	- A 'Damage Type' caused by natural elemental forces
					Lightning Damage	- An 'Elemental Damage' caused by electricity
					Fire Damage 		- An 'Elemental Damage' caused by fire/heat
					Cold Damage 		- An 'Elemental Damage' caused by cold/ice/frost
				Chaos Damage 		- A 'Damage Type' caused by corruption
					
				// Damage mitigation 2 - Defense
				Armor - A 'Character Property' that reduces incoming 'Physical' 'Damage Type' by a percentage (Has a formula)
				Resistance - A 'Character Property' that reduces incoming 'Damage' of a specific 'elemental' or 'chaos' 'Damage Type' by a percentage
				
				// Damage mitigation 2 - Avoidance
				Evasion - A 'Character Property' that affects chance to avoid 'Hit' from an 'attack' or a 'projectile', directly related to 'Accuracy'
				Block - A 'Character Property' that affects chance to prevents 'Damage' from a 'Hit' from an 'attack' or a 'projectile'
				
			
			// Skill 2
			Melee Attack - An 'Attack' that requires close range to perform an 'Execute'. May create an 'Effect' or 'Effect Object'
			Ranged Attack - An 'Attack' that creates a 'Projectile' to 'Execute' at a distance. May create an 'Effect'
			Aura - A 'Passive Skill' that applies a 'Status effect' to all valid targets within an 'Area of effect' around its source
		
		
		
		// (3) Further derived definitions
		
			// Ailment
			Slow - A 'Physical' 'Ailment' that reduces 'movement speed'
			Burn - A 'Fire' 'Ailment' that deals 'damage over time', increading in 'Intensity' by 'movement' at faster 'movement speed' and number of 'Effect stacks'
			Shock - A 'Lightning' 'Ailment' that has a chance to interrupt 'action(s)'
			Chill - a 'Cold' 'Ailment' that reduces 'Action speed' for a 'Duration'
			Corruption - A 'Chaos' 'Ailment' that randomly reverses 'Resource' regeneration
			
			// Impairment
			Stun - A 'Physical' 'Impairment' that prevents 'Action(s)'
			Panic - A 'Fire' 'Impairment' that forces uncontrolled 'movement' at increased 'movement speed' while continuing to 'burn'				
			Paralyze - A 'Lightning' 'Ailment' interrupts 'action(s)' on 'damage' taken
			Freeze - a 'Cold' 'Impairment' that prevents 'movement' for a 'Duration'	
			Entropy - A 'Chaos' 'Impairment' that reverses all 'Resource' regeneration
				
				
					
		// Combat enemy
			Basic enemy - An 'Enemy' that is randomly generated. Can be Normal, uncommon or rare 'Rarity'
			Boss - A powerful 'Enemy' with designed set of 'action(s)' and 'mechanic(s)'




### Game system Descriptions

	Basic game systems and mechanics:
		* Movement 
		* Combat 
		* Resource management
		* Loot 
		* Inventory management 
		* Crafting
		* Progression 
		
	Advanced game systems:
		Social
		Narrative 
		Economy
		Puzzle
		Exploration - ...



## Databases

User Database       - database of users, login and refers to instance database elements
Foundation Database - Foundational database defining core data and rules
Instance Database   - Instances generated based on foundational database

### Database design guidelines

1. When to use enum, column vs table
	We create a new X when an entry is ...
	* Enum
		- Not referenced
		- Small, fixed set of values
		- Rarely changed, only part of a major change
	* Column
		- Not referenced
		- An single variable value
		- Unique to each entry
	* Table
		- Referenced by other tables directly related to it
		- A structure of data
		- It affects a separate system


	

### User database
User database is for reference.

users
	- user_id
	- username
	- email
	- password_hash
	- password_salt
	- created_at
	- is_active
	
roles
	- role_id
	- role_name
	- role_description
	
user_roles
	- user_role_id
	- user_id
	- role_id
	- assigned_at
	
user_sessions
	- user_session_id
	- user_id
	- created_at
	- last_activity
	- expiration_date

### Foundation database		

// Localization
language_codes (Need to support many languages, UTF-8 supports all) (Should be used only for user-facing namings)
	- id
	- language_code (en, fr, de, ...)
	- is_enabled (if language is supported)
	- name (English, French, German, ...)
	- alignment (left aligned or right aligned)
	
character_property_definition_name_translations (example for localization)
		- id
		- attribute_type_definition_id
		- language_code_id
		- name (Strength, Dexterity, Maximum Life, ...) (in that specific language) (even default language for consistency)



// General 
{		
	rarity_type_enum (maybe enum instead)
		- NORMAL
		- UNCOMMON
		- RARE
		- UNIQUE
		
	property_tag (General grouping of a property)
		- id
		- name (physical, damage, life, defense, resource, ...)
		
	property_type
		- id
		- name (Character, Item, Area)

	content_type (What content there is)
		- id
		- name (name of the content)		
}

// Property definition
{		
	// Property
	// Every single character has all Properties
	// Properties define the power and behavior of a character
	// Properties have tags that identify their action
	// Modifier is a set of changes to properties
	// ...
	We have different types of properties (item, character, area)
		Example: 
			* items affix at certain tier modifies properties of the character who has the item equipped.
			
			* item affix at certain tier modifies properties of the item, and therefore the properties of the character who has the item equipped
				- "{0}% Increased attack speed" - Weapon attack speed is changed
				- "Adds {0} - {1} physical damage to attacks"
				
			* Area modifier at certain tier modifies properties of all monsters in the area
				- "{0}% Increased pack size"
				- "{0}% Increased number of Rare Monsters"
				- "Monster skills chain {0} additional times"
				- "Area is inhabited by {0}"
				- "Unique Boss has {0}% increased Life"
				- 

	// What properties exist, It is implicit that a character has all properties
	property_definition
		- property_definition
		- id
		- identifier_name 	(strength, dexterity, intelligence, life, movement_speed, fire/cold/lightning_resistance, max_fire/cold/lightning_resistance, min/max_physical_damage, cannot_be_stunned, ...)
		- name 				(Strength, Dexterity, ...) (Default language name)
		- min_limit 		(Absolute minimum, life cannot be < 0)
		- max_limit 		(Absolute maximum, resistance cannot be > 90, NULL for none)
		
	// List of property tags the property_definition has
	property_definition_property_tag 
		- id
		- property_tag_id
		
	modifier_type_enum
		- LOCAL
		- GLOBAL
		- 
		
	// List of modifiers that modify properties
	modifier_definition  (Index is a number form 0 to N, each index affects a different property)
		- id
		- identifier_name 		("mod_local_flat_physical_damage", "mod_global_flat_physical_damage")
		- name_template 		("Adds {0} - {1} physical damage to attacks" (local flat), "Adds {0} - {1} to physical damage" (global flat)) (name in default language) ({x} is the index from 0 to index_count)
		- description 			(Description of the modifier)
		- index_count			(Number of indexes(values) generated for the modifier)
	
	// Whenever a modifier definition is used, a X_mod_values table is required that identifies its rolls for the modifier
}
	
// Character class and its properties
{
	// What character classes there are
	character_class
		- id
		- identifier_name 
		- name
		- ...
		
	// Base property values for different classes
	character_class_base_property_value
		- id
		- character_class_id
		- property_definition_id
		- base_value
	
	// It is implicit that a character always has EVERY single property from property_definition
	// Actual properties are gathered during gameplay and not stored in the database
	

	// What character does an user have
	user_character
		- id
		- user_id
		- character_class_id
		- name
}


--------

// Passives
{
	// Passives are stored as a table of modifiers

}

--------
// Item
{
	item_type 
		- id
		- name (quest, equipment, crafting_reagent = orb, gold, instance_key = map) 
		
	/*
	Item - A General term for all items that can drop, picked up and managed in the inventory
	Quest - Item that is part of a quest and cannot be traded. (exchangeable, consumable, sellable)
	Equipment - Item that can be equipped by a character (equippable)
	Crafting Reagent - Item that can be consumed and applied to an item (stackable, usable on an item)
	Gold - Item as a numeric value allocating used for basic services.
	Instance key - Item for managing instances to an area.	
	*/
}

// Equipment - Tables for equipment
{
	// What class of equipments there are (body_armour, 1h_sword, 2h_sword, wand)
	equipment_class
		- id
		- name
		
	// 
	equipment_base (ragged_leather_armour, fine_leather_armor, ..., jewel)
		- id
		- equipment_class_id
		- name
	
	// equipment class properties - One table for each equipment_class
	{
		armor_base_properties
		- id
		- equipment_base_id
		- armor_type
		- base_armor
		- evasion
		- barrier
		
		// One for each equipment_base
		*_base_properties 
	}
	
	// Each base has separate requirements
	equipment_base_requirements
		- id
		- equipment_base_id
		- level_required
		- str_required
		- dex_required
		- int_required
}

// Orb - Tables for orbs
{
	...
}

// 

----------
	
// Item affix
{
	// Contains all and every affix

	item_affix_type_enum
		- IMPLICIT
		- PREFIX
		- SUFFIX
		- PREFIX
		- ENCHANT

	prefix_flat_added_physical_damage ({0}, {1})
	prefix_more_physical_damage({0})
	suffix_added_life({0})
	suffix_more_life({0})
	suffix_hybrid_flat_added_physical_damage_more_physical_damage_added_armor({0} {1} {2} {3})

	// Define what affixes exist, including hybrid ones
	item_affix_definition
		- id
		- identifier_name 			("prefix_flat_physical_damage")
		- item_affix_type_enum  	(What type of affix it is)
		
	// Where can an affix spawn ( what item class)
	item_affix_equipment_class (body, gloves)
		- id
		- item_affix_definition_id
		- equipment_class_id
		
	// Where can an affix spawn (what type of content it is from)
	item_affix_definition_content_type
		- id
		- content_type_id
		- item_affix_definition_id

	// What does the affix affect ( What character property does the index of the affix affect)
	item_affix_mod_values (index_count of item_affix_definition entries per item_affix_family_id, one index can affect many character properties)
		- id
		- item_affix_definition_id
		- value_index 						(index from 0 to (index_count-1))
		- character_property_definition_id 	(What character property that index of the affix affects)
		- value_type						(additive, multiplicative) 
		
	// What tags does the affix have			
	item_affix_definition_property_tag (What property tags does the item affix have)
		- id
		- item_affix_definition_id
		- property_tag_id
	
	
	//Exclusion
	
	// Define what exclusions groups there area (If an affix appears in a group, other affixes in that group cannot be rolled)
	item_affix_exclusion_group (Group of affixes that cannot appear together)
		- id
		- identifier_name (self_exclusion, physical_damage_conversion, stun_immunity, damage_type_negation)
		- description (Why those cant appear together) (no duplicates, convert phys to lighting + convert phys fire, cannot be stunned + increased stun threshold, Deal no physical + deal only physical, cannot attack + cannot cast spells )
		
	// Which affixes are in which exclusion group
	item_affix_definition_exclusion (What affix appears in an exclusion group)
		- id 
		- item_affix_definition_id 
		- exclusion_group_id          
		
		
	//Tiers				
	
	// How many tiers does an affix have
	item_affix_tier_definition (How many different levels of a specific affix definition we have)
		- id 
		- item_affix_definition_id
		- tier 				(Higher = better)
		- item_level_min 	(Minimum item level that this affix of that tier can appear on)
		- item_level_max 	(Maximum item level that this affix of that tier can appear on)
		
	// What are the values of a given affix's tier
	item_affix_tier_value (Defines a roll for an item affix tier) (index_count of item_affix_definition entries per tier, only one index for every index_count per tier)
		- id
		- item_affix_tier_definition_id
		- value_index (index from 0 to (index_count-1))
		- min_value
		- max_value
}

// Unique item
{
	unique_item
		- id 
		- equipment_base_id
		- ...
	
	unique_requirement
		- id
		- unique_item_id
		- ...
	
	unique_affix
		- id
		- unique_item_id
		...
}





///// OLD	

## Data layers
? What was that for ?

Database
	//Static - always same, contains all ground truth information loaded into service memory
	GroundTruth database:
		Modifier table
		ItemBase table
		AffixRoll table 
		Unique item table
		<other supporting tables>
		CharacterClass
		
	User database
		Users		
		
	//Dynamic - dev/test/live References only GroundTruth/User database tables
	Dynamic Database:
		CharacterProgress
		CollapsedItem table
		User Characters
		
	
DataEntry
	ModifierEntry
	ItemBaseEntry
	AffixRollEntry
	UniqueItemRollEntry
	CharacterEntry
	CollapsedItemEntry
	
	
BaseDAO(Abstract) -> DataEntry | DAO = Data Access Object
	Modifier DAO
	ItemBase DAO
	AffixRoll DAO
	UniqueItemRoll DAO
	<Other supporting table DAO>
	
SQLDAO (Database) -> DataEntry
	Overloaded BaseDAO
	Example: 
		MySQLModifierDAO
		PostgreSQLModifierDAO
	...
	


Object
	Character
	Modifier
	ItemBase
	<Types>
	Affix
	UniqueItem
	Item
	...
	
Generation -> Object
	AffixGenerator
	ItemGenerator
