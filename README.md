## Database

	### Description		
	User Database       - database of users, login and refers to instance database elements
	Foundation Database - Base foundational elements of the project
	Instance Database   - unique instanced based on foundational elements, referring to foundational entries

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

	// Base info tables v2
	{	
		
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
			property_tag (General grouping of a property)
				- id
				- name (physical, damage, life, defense, ...)
			
			content_type (What content there is)
				- id
				- name (name of the content)
		}
			
	
	
	
		// Character property
		{
		
			character_property_type (type of property)
				- id
				- name (static, variable, dynamic)
				
			character_property_definition (All character properties, even resources, be them current values like current_life, calculated values like max_life)
				- id
				- identifier_name 	(strength, dexterity, intelligence, min_life, current_life, max_life, base_life, movement_speed, min/max_resistance/physical_damage)
				- name 				(Strength, Dexterity, ...) (Default language name)
				- property_type_id
				- min_limit 		(life cannot be < 0)
				- max_limit 		(resistance cannot be > 90, NULL for none)
				
			character_property_property_tag (what property tags does the character property have )
				- id
				- property_tag_id
		}
		
		--------
		
		// Base item stuff
		{
			item_class
				- id
				- name
				
			item_base ()
				- id
				- item_class_id
				- name
			
			rarity_type (maybe enum instead)
				- id
				- name
			
			// item class properties - One table for each item_class
			{
				armor_base_properties (each armor base has their own properties)
				- id
				- item_base_id
				- armor_type
				- base_armor
				- evasion
				- barrier
			}
			
			item_base_requirements  (each base has a separate requirement)
				- id
				- item_base_id
				- level_required
				- str_required
				- dex_required
				- int_required
			
		// Item affix
		{
			item_affix_type
				- id 
				- name ("prefix", "suffix", "implicit", "enchant", ...)
		
			item_affix_definition (What the affix is) (Index is a number form 0 to N, each index affects a different character property)
				- id
				- identifier_name 		("flat_physical_damage")
				- name_template 		("Adds {0} - {1} to physical damage") (name in default language) ({x} is the index from 0 to index_count)
				- description 			(Description of the affix)
				- index_count			(Number of indexes(values) generated for the affix)
				
			item_affix_definition_content_type (What affix can spawn where)
				- id
				- content_type_id
				- item_affix_definition_id
				
				
			//Affix-ItemClass				
			item_affix_item_class (What item classes can the affix spawn for) (body, gloves)
				- id
				- item_affix_definition_id
				- item_class_id

			//Affix-Character			
			item_affix_definition_character_property (What character property does the index of the affix affect) (index_count of item_affix_definition entries per item_affix_family_id, one index can affect many character properties)
				- id
				- item_affix_definition_id
				- value_index 						(index from 0 to (index_count-1))
				- character_property_definition_id 	(What character property that index of the affix affects)
				- value_type						(additive, multiplicative) 
				
			//Tag			
			item_affix_definition_property_tag (What property tags does the item affix have)
				- id
				- item_affix_definition_id
				- property_tag_id
			
			//Exclusion (If an affix appears in a group, other affixes in that group cannot be rolled)
			item_affix_exclusion_group (Group of affixes that cannot appear together)
				- id
				- identifier_name (self_exclusion, physical_damage_conversion, stun_immunity, damage_type_negation)
				- description (Why those cant appear together) (no duplicates, convert phys to lighting + convert phys fire, cannot be stunned + increased stun threshold, Deal no physical + deal only physical, cannot attack + cannot cast spells )
				
			item_affix_definition_exclusion (What affix appears in an exclusion group)
				- id 
				- item_affix_definition_id 
				- exclusion_group_id          
			
			//Tiers				
			item_affix_tier_definition (How many different levels of a specific affix definition we have)
				- id 
				- item_affix_definition_id
				- tier 				(Higher = better)
				- item_level_min 	(Minimum item level that this affix of that tier can appear on)
				- item_level_max 	(Maximum item level that this affix of that tier can appear on)
				
			item_affix_tier_value (Defines a roll for an item affix tier) (index_count of item_affix_definition entries per tier, only one index for every index_count per tier)
				- id
				- item_affix_tier_definition_id
				- value_index (index from 0 to (index_count-1))
				- min_value
				- max_value
		}
		
		
		// Unique
		{
			unique_item
				- id 
				- item_base_id
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
	}




///// OLD	


	// Base info tables
	{
		Modifier
			- modifier_id
			- modifier_name
			- modifier_description
			
		rarity
			- rarity_id
			- rarity_name
			
		item_base_slot
			- item_base_slot_id
			- item_base_slot_name
			
		affix_type
			- affix_type_id
			- affix_type_name
			
		tags
			- tag_id
			- tag_name
	}

	// Rollable  information
	{
		item_base
			- item_base_id
			- item_base_slot_id
			- item_base_name
			- item_base_nametag
		affix_constraints
			- affix_constraint_id
			- affix_constraint_name
		affix
			- affix_id
			- affix_tier
			- affix_name
			- affix_nametag
			- affix_level
			- affix_constraint_id_list - Create another link-table
			- tag_id_list			   - Create another link-table
	}
	
	### Instance database
	{
		collapsed_items
			- item_id
			- item_name //collapsed item name = <one_prefix><item_base_name><one_suffix>
			- rarity_id
			- item_base_id
			- item_base_stats_nosql
			- item_affix_count
			- item_affixes_nosql
	}



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
