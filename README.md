# ItemGenerator
Generated item instances 

# Databases
## Description
	Foundation Database - Base foundational elements of the project
 	Instance Database   - unique instanced based on foundational elements, referring to foundational entries
  	User Database       - database of users, login and refers to instance database elements
## Database Table Schema
	User database
		users
			user_id
			username
			email
			password_hash
			password_salt
			created_at
			is_active
		roles
			role_id
			role_name
			role_description
		user_roles
			user_role_id
			user_id
			role_id
			assigned_at
		user_sessions
			user_session_id
			user_id
			created_at
			last_activity
			expiration_date
		
	Foundation database
		//Base info tables
		Modifier
			modifier_id
			modifier_name
			modifier_description
		rarity
			rarity_id
			rarity_name
		item_base_slot
			item_base_slot_id
			item_base_slot_name
		affix_type
			affix_type_id
			affix_type_name
		tags
			tag_id
			tag_name
		
		//Rollable  information
		item_base
			item_base_id
			item_base_slot_id
			item_base_name
			item_base_nametag
		affix_constraints
			affix_constraint_id
			affix_constraint_name
		affix
			affix_id
			affix_tier
			affix_name
			affix_nametag
			affix_level
			affix_constraint_id_list - Create another link-table
			tag_id_list			     - Create another link-table
			
	Instance database
		collapsed_items
			item_id
			item_name //collapsed item name = <one_prefix><item_base_name><one_suffix>
			rarity_id
			item_base_id
			item_base_stats_nosql
			item_affix_count
			item_affixes_nosql


Data layers

Database
	//(Static - always same) Contains all ground truth information loaded into service memory
	GroundTruth database:
		Modifier table
		ItemBase table
		AffixRoll table 
		Unique item table
		<other supporting tables>
		CharacterClass
		
	User database
		Users		
		
	//(Dynamic - dev/test/live) References only GroundTruth/User database tables
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
	
	
BaseDAO(Abstract) -> DataEntry
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










#//////////Maybe something like this//////////

//Item layer
enum class EItemClass
{
	NONE,
	CONSUMABLE,
	EQUIPMENT,
	CONTAINER,
	CRAFTING_ORB,
	QUEST_ITEM
};

struct EItemType
{
	enum class EConsumableType
	{
		GENERIC = 0
	};
	
	enum class EEquipmentType
	{
		GENERIC 	= 0,
		BODY        = 1,
		HANDS       = 2,
		BELT        = 3,
		RING        = 4,
		AMULET      = 5,
		WEAPON_1H   = 6,
		WEAPON_2H   = 7,
		OFFHAND     = 8,
		HEAD        = 9,
		LEGS        = 10,
	};
	
	enum class EContainerType
	{
		GENERIC = 0
	};
	
	enum class ECraftingOrbType
	{
		GENERIC = 0
	};
	
	enum class EQuestItemType
	{
		GENERIC = 0
	};
};


//Equipment layer

//One of those for each implemented type ?

EItemType::EEquipmentType::GENERIC

//Mono or separated Weapon, armor types ?
enum class EWeaponBaseType
{
//Weapon
	SWORD_1H,
	SWORD_2H,
	
	AXE_1H,
	AXE_2H,
	
	MACE_1H,
	MACE_2H,
	
	BOW
};

enum class EArmorType
{
	CLOTH,
	LEATHER,
	MAIL,
	PLATE
};