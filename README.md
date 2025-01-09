# Description		

## General definitions

// Foundation
World - Environment that an 'Entity' exists and moves around in, where all 'actions' take place
Instance - A unique, isolated copy of a 'world'
Instance state - Current status of an 'instance'
Entity - Any fundemental object in the 'world' that can be interacted with
Entity state - Current status of an 'entity'
Action - Any operation that can be performed by an entity that affects a 'Instance state' or an "Entity state"
Content - A Designed gameplay element that can be interacted with or experienced

// User
Account - Collection of characters, stash and persistent data owned by a user
Player - User currently active in an 'instance'

// 
Prop - A static 'entity' that cannot perform 'actions' but can be interacted with
Character - A dynamic 'entity' controlled by a player or an AI
Character class - Template that defines a set of base properties for a Player character
Character property - A numeric value or flag that is one variable of a 'Character's' state
Property tag - Label that categorizes the type of a 'property'
Effect - Temporary or permanent modification to an 'instance state' or 'character property'
Ground effect - Temporary modification to a 'instance state'
Status effect - Temporary modification to a 'character property'
Modifier - additive or multiplicative value that changes any property or properties

//
Player character - 'Character' controlled by a 'player'
NPC - 'Character' controlled by an AI that is not hostile towards the 'player'
Enemy - 'Character' controlled by an AI that is hostile towards the 'player'

// Action 
Skill - A designed 'action' or a 'modifier' granted to a 'character'
Active Skill - An 'action' granted to a 'character'
Passive Skill - A 'modifier' granted to a 'character'
Resource - A limited pool of a specific energy that's used to perform certain 'Active Skills'

// Item
Item - A general term for all objects that can be picked up, carried, dropped 
Rarity - Item classification that determines how uncommon and how powerful it can be
Loot - Items that are obtained from defeated monsters, from containers or as a reward
Inventory - Container for 'items' currently being carried by a 'Character'
Stash - Container for 'items' permanently stored by a 'character' or 'account'
Equipment - Item that can be equipped by a 'character' that affects its 'Entity State'
Equipment slot - A designated position where an single piece of 'equipment' can be put on an 'Entity' that affects its properties
Equipment type - a specific type of 'equipment' that can only be equipped into a certain 'equipment slot'
Equipment properties - A unique set of numeric values or flags for a certain 'equipment type' that affects 'Character properties'
Affix - 'Modifier' that can be added to an item that changes either 'character property' or 'equipment property'
Weapon - An Equipment in a specific 'equipment slot' that is used for specific 'Actions' and interacting with 'Enemies'

//
Attack - A damaging 'Active skill' directly damaging an 'Enemy' with a 'weapon' that uses the 'weapon's' 'equipment properties' as the source of the damage. Have a chance to miss. Can cause 'Effects'. Only usable with certain 'weapon' types.
Spell - A damaging 'Active skill' indirectly damaging an 'Enemy' with a 'weapon' that does NOT use 'weapon's' 'equipment properties' as the source of the damage. Cannot miss. Is an 'Effect' and can cause 'Effects'
Buff - A Positive 'Status effect'
Debuff - A Negative 'Status effect'

## Databases

User Database       - database of users, login and refers to instance database elements
Foundation Database - Foundational database defining core data and rules
Instance Database   - Instances generated based on foundational database



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
		
	content_type (What content there is)
		- id
		- name (name of the content)
		
}

// Property definition
{		
	// What properties exist, It is implicit that a character has all properties
	property_definition
		- id
		- identifier_name 	(strength, dexterity, intelligence, life, movement_speed, fire/cold/lightning_resistance, max_fire/cold/lightning_resistance, min/max_physical_damage, cannot_be_stunned, ...)
		- name 				(Strength, Dexterity, ...) (Default language name)
		- min_limit 		(Absolute minimum, life cannot be < 0)
		- max_limit 		(Absolute maximum, resistance cannot be > 90, NULL for none)
		
	// List of property tags the property_definition has
	property_definition_property_tag 
		- id
		- property_tag_id
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
	character_class_base_property
		- id
		- character_class_id
		- property_definition_id
		- base_value
	
	// It is implicit that a character always has EVERY single property from property_definition
}

--------

// Passives
{

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
	item_affix_type_enum
		- IMPLICIT
		- PREFIX
		- SUFFIX
		- PREFIX
		- ENCHANT

	// Define what affixes exist
	item_affix_definition  (Index is a number form 0 to N, each index affects a different character property)
		- id
		- identifier_name 		("flat_physical_damage")
		- name_template 		("Adds {0} - {1} to physical damage") (name in default language) ({x} is the index from 0 to index_count)
		- description 			(Description of the affix)
		- index_count			(Number of indexes(values) generated for the affix)
		- item_affix_type_enum  (What type of affix it is)
		
	// Where can an affix spawn
	item_affix_definition_content_type (what content type)
		- id
		- content_type_id
		- item_affix_definition_id
		
	// Where can an affix spawn ( what item class)
	item_affix_equipment_class (body, gloves)
		- id
		- item_affix_definition_id
		- equipment_class_id

	// What does the affix affect ( What character property does the index of the affix affect)
	item_affix_definition_character_property (index_count of item_affix_definition entries per item_affix_family_id, one index can affect many character properties)
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
