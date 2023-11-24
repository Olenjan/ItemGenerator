# ItemGenerator
Generated item instances 

## Databases
	Foundation Database - Base foundational elements of the project
 	Instance Database   - unique instanced based on foundational elements, referring to foundational entries
  	User Database       - database of users, login and refers to instance database elements

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

	
