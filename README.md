# Description		

## General definitions
See Definitions.md


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
