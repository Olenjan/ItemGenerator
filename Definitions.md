# definitions

## Basic definitions

	### User
	Account - A persistent collection of data and privileges with unique login information
	User 	- A logged in 'account' interacting with system-level services 

	### Game
	Game 		- An interactive environment with defined rules, states, objectives
	Player 		- A 'User' who interacts with the 'game'
	AI			- An Artificial intelligence who makes complex decision and interacts with the 'game'
	Game client - Software running on 'user(s)' device that the 'Player' is using to interact with the 'game'
	Game server	- Authoritative software system defining and controlling the 'game(s)' state, running on dedicated hardware or cloud infrastructure

	### Engine
	Entity 				- A Unique identifier representing a distinct, independent, or self-contained unit.
	Entity component	- A single piece of data that describes one aspect of an 'entity'
	Entity system 		- A single logic module that describes how 'entity(ies)' with a set of 'Components' are processed
	Transformation 		- A specific Position, , rotation scale of an 'Entity'
	Scene 				- An arrangement of 'entity(ies)', their 'transformation(s)' and their relationships
	Art 				- A single basic piece of engine resource: texture, mesh, animation or sound
	Asset				- A single complex piece of engine resource: Model, hitbox, Material, VFX, Entity behavior, ...
	Template Entity		- A complex 'Entity', its 'Component(s)' and a set of 'Asset(s)'. Is an itself an 'Asset'

	### Core engine systems
	Graphics		- A visual representation 'entity(ies)'
	Audio			- An auditory representation 'entity(ies)'
	Physics 		- A set of rules governing physical 'Entity(ies)' and how they move, interact with each other through forces and collisions
	Entity Behavior - A Scripted behavior of an 'Entity'

	### Gameplay
	Gameplay system - A set of interacting rules that defined a specific part of a 'game'
	Mechanic - A functional component of a 'game system'
	Gameplay - Emergent patterns of interaction between a 'player' and a set of 'game system(s)'
	Content - Deliberately designed experience delivered through 'game system(s)'

## Game basics

	Surface 	- Immutable structure 'Entity' within a 'scene' that has a physical boundary and visual representation.
	Playspace 	- The total volume within 'scene' enclosed by 'surface(s)' where gameplay can occur

	Object 			- A non-abstract 'Entity', with physical form, within a 'playspace' that cannot exit the 'playspace'. Is not a 'surface'
	Prop 			- An 'object' within 'playspace' that enhances visual detail and ambiance. Can have basic 'Entity behavior'
	Destructible 	- A temporary 'prop' that can be removed from the 'playspace' through interaction	
	Actor			- An autonomous 'Object' that has controlled 'Entity behavior'

	Tileset - A collection of reusable 'surface(s)' and 'prop(s)' designed to be used together to construct consistent 'playspace'
	Layout	- A set of instructions defining how a 'tileset' is arranged. Either fixed, randomly or semi-random
	Area 	- A 'playspace' built from a set of possible 'tileset(s)' and 'layout(s)'
	Zone 	- A collection of connected 'Area(s)' sharing a progressing theme
	World 	- A collection of interconnected 'zone(s)'


## Gameplay conceptual axioms
	//L0 - Technical layer
	Asset			- How Everything manifests itself
	Transformation 	- What Everything occupies
	Physics			- What Everything is governed by

	//L1 - Fundemental layer
	Property 		- Everything that qualifies
	Environment 	- Everything that is there						- Environments are fundemental, exists, have properties
	Character 		- Everything that are doing						- Characters are fundemental, exist, have properties
	Item 			- Everything that is had						- Items are fundemental, exist, have properties
	Action 			- Everything that is done						- Actions are fundemental, they happen, have properties

## Gameplay layers

	### Fundemental layer
		Fundamental	- A single instance of either the "Environment", a "Character", an "Action" or an "Item"
		Property 	- A numeric value or a flag that qualifies one aspect of a 'Fundamental'
		Environment - A specific instantiation of an 'Area' using one selected 'Layout' and 'Tileset' from its possible sets
		Character 	- An 'Actor' controlled by a 'Player' or an 'AI'
		Item 		- An 'Object' that can owned by a 'Character'
		Action 		- A single 'Entity behavior' of an 'Actor'
		

	### Base layer
		Player character	- A 'Character' controlled by a 'player'
		Self 				- A reference to the acting 'Player Character'
		NPC 				- A 'Character' that may be controlled by an 'AI' that is friendly towards the 'player'
		Enemy 				- A 'Character' that may be controlled by an 'AI' that is hostile towards the 'player'
		
		Power 				- Overall effectiveness of a 'Character'
		
		Modifier	- Additive or multiplicative numberical value that passively changes 'property(ies)'
		Effect 		- Additive or multiplicative numberical value that actively changes 'property(ies)'

		Skill 			- Every 'Character' related 'Action' that changes a 'Character(s)' 'property(ies)'
		Basic Action	- Any 'Action' that is not a 'Skill'

	### Gameplay base systems layer 
	
		#### Environment
			Dungeon generation system - How 'Environment(s)' are generated
			
		#### Character
			Character class 	- What 'character' classes there are and what defined their 'Power'
			Player progression	- Where and how do 'Player character(s)' get their 'Power'
			Enemy progression 	- Where and how do 'Enemy(s)' get their 'Power'
			
		#### Items
			Item system			- What items exist
			Loot System			- How Items are generated
			Inventory system	- How items are stored/managed by 'Player(s)'
			Equipment system 	- How Items are worn/used by 'Characters'
			Crafting system		- How items are created by 'Player(s)' in a semi-deterministic way
			
		#### Action
			Movement system - How 'Character(s)' move in the 'Environment'
			Skill system 	- What 'Skill(s)' there are 
			Combat	system 	- Interaction between 'Player character(s)' and 'Enemy(ies)'
			
	### Gameplay advanced systems layer
		Activity 			- 
		Encounter  			- 
		
...

## Gameplay Advanced layer definitions
...
	
## Gameplay definitions (Old)

	### Base definitions
	//
	Property - A numeric value or flag that is one variable of a state for a 'mechanic' or a set of 'mechanic(s)' across 'game system(s)'
	Property tag - Label that categorizes the type of a 'property'
	Modifier - additive or multiplicative value that changes one or more 'property(ies)'
	
	Character - An 'Actor' controlled by a player or an AI
	Progression point - A value that can be spent to increase a permanently change 'Character(s)' 'Property(ies)'
	
	Item - An 'Object' or an 'Entity' that can be picked up, carried, dropped and possibly used by a 'Character'. Is of certain 'Rarity'
	Equipment - An 'Inventory item' that can be worn or wielded by a 'Character' to provide benefits

	### Character types(What)
	Player character - A 'Character' controlled by a 'player'
	Self - A reference to the acting 'Player Character'
	NPC - A 'Character' controlled by an AI that is friendly towards the 'player'
	Enemy - A 'Character' controlled by an AI that is hostile towards the 'player'
	
	### Activity
	Activity - An interaction with one or more 'game system(s)' that a 'Character' can participate in
	Objective - A designed goal that requires completing one or more 'activity(ies)'
	Reward - 'Item(s)' or 'Progression point(s)' that are obtained by completing an 'objective'
	
	### Property types	
	Character property - a set of 'Property(ies)' of a 'Character'
	Equipment property - a unique set of 'Property(ies)' of an 'Equipment' of type
	Instance property - a set of 'Property(ies)' that affect an entire 'Instance' and all 'Enemy(s)' within it.

		#### Character property
		Resource - A 'property' of a 'character' spent by doing certain 'action(s)' and regenerated by a 'Character'
		Regeneration - A 'Property' that passively restored a 'Resource' per second for the 'Character'
		...
		
		#### Equipment property
		...
		
		#### Instance property
		...



	### Core Systems - Separate interacting modules (Data + Logic)
	* Property system   - All 'things' have a property 		(Foundation)
	* Character system 	- Character data and progression 	(Framework)
	* Movement system 	- Movement within a world		 	(Framework)
	* Item system  		- Items that a character can equip	(level 1 - Built on 'Character system')
	* Combat system		- How 'Character  with hostile characters (level 2 - Built on 'Character' , 'Movement' and 'Item system')
	* Difficulty system - How hard is the  Combat			(Level 3 - )
	
	* Objective system 	- What to do (level 3 - Based on Combat)
	* Encounter systems -  What to do (level 3 - Based on Combat)
	
	... Where is 'reward'
	
	// Maybe player facing?
	
	* Gameplay systems
		- Character class
		- Combat/skills
		- Movement
		- Resource
		- Status effects
	* Progression & Items
		- Character development
		- Equipment/Inventory
		- Loot
		- Crafting
		- Trading
	
	* Content systems
		- Quests, objectives
		- Encounters
		- World, areas
		- Difficulty
	
	---
	
		#### Character system
		Character class - Template that defines base values for 'property(ies)' of a 'Character'
		Character Power - A set of 'Character property(ies)' that represents the overall 'Combat' effectiveness of a 'Character'
		Passive Tree - A structured collection of permanent increases to 'property(ies)' that can be acquired by spending 'Progression point(s)' to increase 'Character Power'
		Level - A discrete rank that represents a 'Character's' overall progression and number of base 'Progression point(s)' they have obtained
		Experience - A value that measures a 'Character's' progress towards gaining a 'Level'. Percentage progress towards obtaining a 'Progression point'

		
		#### Movement system
		
		#### Item system 
		
		Problem - A complication or difficulty that reduces play experience and needs to be resolved by the 'player'
		Itemization - The complete set of meaningful 'Equipment' choices available to a 'Character' to solve 'Problem(s)'
		Affix - A single 'Modifier' that is part of an item
		Item Type - A category of 'Item' that determines how it can be used
		Inventory - a Limited storage space for 'item(s)' currently being carried by a 'Character'
		Stash - A Persistent storage space for 'item(s)' permanently stored by a 'character' or an 'account'
		Ground item - an 'Item' that exists as an 'Object' within an 'instance'
		Inventory item - an 'Item' that exists as an 'Entity' within a 'Character(s)' 'Inventory' or 'Stash' 
		Equipment Type - A specific category of 'Equipment' that determines how it can be worn or wielded
		Equipment slot - A designated position where a single piece of 'equipment' of certain 'Equipment Type' can be put on a 'Character'
		Container - An 'Object' in an 'Instance' that can dispense 'Item(s)'
		Loot - 'Item(s)' that are obtained from defeated 'Enemy(s)', from 'Container(s)' or as a 'Reward'
			
		
		#### Combat system
		Combat - A state where 'Character(s)' engage in conflict with each other
		
		#### objective system
		
		#### Boss/Challange systems









## Gameplay


### Character
		Character - An 'Actor' controlled by a player or an AI
		Player character - A 'Character' controlled by a 'player'
		Self - A reference to the acting 'Player Character'
		NPC - A 'Character' controlled by an AI that is friendly towards the 'player'
		Enemy - A 'Character' controlled by an AI that is hostile towards the 'player'
		Resource - A 'property' of a 'character' spent by doing certain 'action(s)' and regenerated by a 'Character'
		Regeneration - A 'Property' that passively restored a 'Resource' per second for the 'Character'




### Basics
Rarity - An abstract classification that determines how uncommon and powerful something is. (Normal, Uncommon, Rare, Unique)
		Item - An 'Object' or an 'Entity' that can be picked up, carried, dropped and possibly used by a 'Character'. Is of certain 'Rarity'


		Property - A numeric value or flag that is one variable of a state for a 'mechanic' or a set of 'mechanic(s)' across 'game system(s)'
		Modifier - additive or multiplicative value that changes one or more 'property(ies)'

		Progression point - A value that can be spent to increase a permanently change 'Character(s)' 'Property(ies)'

		Combat - A state where 'Character(s)' engage in conflict with each other


		Activity - An interaction with one or more 'game system(s)' that a 'Character' can participate in
		Objective - A designed goal that requires completing one or more 'activity(ies)'
		Reward - 'Item(s)' or 'Progression point(s)' that are obtained by completing an 'objective'


### Item Basics
		Problem - A complication or difficulty that reduces play experience and needs to be resolved by the 'player'
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
	


### Gameplay properties 
		Character property - a set of 'Property(ies)' of a 'Character'
		Equipment property - a unique set of 'Property(ies)' of an 'Equipment' of type
		Instance property - a set of 'Property(ies)' that affect an entire 'Instance' and all 'Enemy(s)' within it.
		Property tag - Label that categorizes the type of a 'property'


### Character
		Character class - Template that defines base values for 'property(ies)' of a 'Character'
		Character Power - A set of 'Character property(ies)' that represents the overall 'Combat' effectiveness of a 'Character'
		Passive Tree - A structured collection of permanent increases to 'property(ies)' that can be acquired by spending 'Progression point(s)' to increase 'Character Power'
		Level - A discrete rank that represents a 'Character's' overall progression and number of base 'Progression point(s)' they have obtained
		Experience - A value that measures a 'Character's' progress towards gaining a 'Level'. Percentage progress towards obtaining a 'Progression point'

---

### Gameplay systems
	
	#### Character system
	Character class subsystem - A subsystem that gives a 'character' base 'Character power'
	Leveling subsystem - 
	Skill subsystem - A subsystem that provides permanent increases to 'Character Power' through investment of 'Progression points' in the 'Passive tree'
	Leveling subsystem - A subsystem that governs how a 'Character' gains 'Experience', reaches new 'Level(s)', and receives 'progression point(s)' through gameplay activities

	#### Movement system
	Movement system - A 'game system' that governs how a 'Character' traverses the 'environment' in an 'instance'

	#### Item system 
	low to high reward - Having clean inventory, Looting or crafting a good item
	
	Item system - A 'game system' that governs everything related to 'Item(s)' and 'itemization'
	Inventory management subsystem - A subsystem that governs how 'Item(s)' are stored, organized, and handled by a 'Character'
	Loot subsystem - A subsystem that governs how 'loot' is generated
	Crafting subsystem - A subsystem that governs how 'Item(s)' are created or modified by a 'Player'
	
	Equipment subsystem - A subsystem that affects 'Character power' through 'Equipment'.
	
	#### Progression system
	Medium to high reward - Increasing character power
	Progression system - ...
	
	#### Combat system
	Low to High reward - Surviving a difficult encounter
	Combat system - A 'game system' that governs how 'Character(s)' engage in conflict with each other in an 'instance'
	
	#### objective system
	Low to medium reward - Finish a campaign or a long questchain
	Quest system - ...
	Campaign system - ...

	#### Boss/Challange systems
	edium to high reward - Killing a difficult boss
	Boss system - ...
	
	
---

##### Movement Basics - Movement system

##### Item Basics - Item system


##### Progression Basics - Progression system
	Medium to high reward - Increasing character power is rewarding

	
	
	
	
	

##### Combat Basics (1) - Combat system
	
	Target - An 'Actor', a 'prop', a 'Position' or 'Self' that will receive the 'effect(s)' of an 'action'	
	Life - 'Resource' representing health of the 'Character' that results in death when reading zero
	Mana - 'Resource' that is required to perform certain 'Actions'. More powerful actions consume more of that 'Resource'
	Reserve - A portion of a 'Resource' that becomes unavailable for consumption while maintaining a specific 'Effect' or 'Passive Skill' active
		
	###### Effect
	Effect - A temporary or permanent 'Modifier' on a 'Target(s)'
	Effect stack - A cumulative instance of an 'Effect' that can build up on a 'Target'
	Effect Object - A temporary 'object' created by an 'Action' within an 'instance' and can affect 'Target(s)'
	Area of Effect - A "Character property" that affects the volume within the 'instance' where an 'Effect' or 'Effect Object' will affect all valid 'Target(s)'	
	Duration - A finite time period during which an 'Effect' or 'Effect Object' remains active


	###### Damage
	Damage - A negative 'Effect' that reduces a 'Target(s)' 'Life' 'Resource'
	Damage Type - A 'Property tag' that determines how 'Damage' interacts with defensive 'Property(ies)'
	Damage over Time (DOT) - 'Damage' of a certain 'Damage type' that is applied repeatedly at fixed intervals over a 'Duration'
	Weapon - 'Equipment type' that enables 'Character' to perform certain types of damaging 'Action(s)'

	###### Damage mitigation
	Heal - A positive 'Effect' that restores a 'Target(s)' 'Life' 'Resource'
	Defense - A 'Character Property' that reduces incoming 'Damage'
	Avoidance - A 'Character Property' that gives a chance to avoid incoming 'Damage'

	###### Skill
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


##### Combat Basics (2) - Combat system

	###### Effect (2)					
	Status Effect - A temporary 'Effect' that modifies a 'Character Property(ies)' or 'behavior'
	Ground Effect - An 'Effect Object' that persists in an 'instance' and can affect 'Target(s)' within its 'Area of Effect'	
	Buff - A Positive 'Status effect'
	Debuff - A Negative 'Status effect'
	Ailment - A 'Debuff' that partially disrupts for a certain 'Duration' caused by a repeatedly being dealt a specific 'Damage Type' or by specific 'Skill(s)'
	Impairment - A 'Debuff' that fully disrupts for a certain 'Duration' caused by reaching a threshold of 'Ailment' 'Effect stack(s)' or triggered by specific 'Skill(s)'
		
	###### Damage (2)
	**Damage (2) - damage**
	Accuracy - A 'Character Property' that affects chance of 'Hit' with an 'Attack'
		
	**Damage (2) - Damage type**
	Physical Damage 	- A 'Damage Type' caused by physical means
	Elemental Damage 	- A 'Damage Type' caused by natural elemental forces
		Lightning Damage	- An 'Elemental Damage' caused by electricity
		Fire Damage 		- An 'Elemental Damage' caused by fire/heat
		Cold Damage 		- An 'Elemental Damage' caused by cold/ice/frost
	Chaos Damage 		- A 'Damage Type' caused by corruption
		
	**Damage mitigation (2) - Defense**
	Armor - A 'Character Property' that reduces incoming 'Physical' 'Damage Type' by a percentage (Has a formula)
	Resistance - A 'Character Property' that reduces incoming 'Damage' of a specific 'elemental' or 'chaos' 'Damage Type' by a percentage

	**Damage mitigation (2) - Avoidance**
	Evasion - A 'Character Property' that affects chance to avoid 'Hit' from an 'attack' or a 'projectile', directly related to 'Accuracy'
	Block - A 'Character Property' that affects chance to prevents 'Damage' from a 'Hit' from an 'attack' or a 'projectile'
			
		
	**Skill 2**
	Melee Attack - An 'Attack' that requires close range to perform an 'Execute'. May create an 'Effect' or 'Effect Object'
	Ranged Attack - An 'Attack' that creates a 'Projectile' to 'Execute' at a distance. May create an 'Effect'
	Aura - A 'Passive Skill' that applies a 'Status effect' to all valid targets within an 'Area of effect' around its source

##### Combat Basics (3) - Combat system
	**Ailment**
	Slow - A 'Physical' 'Ailment' that reduces 'movement speed'
	Burn - A 'Fire' 'Ailment' that deals 'damage over time', increading in 'Intensity' by 'movement' at faster 'movement speed' and number of 'Effect stacks'
	Shock - A 'Lightning' 'Ailment' that has a chance to interrupt 'action(s)'
	Chill - a 'Cold' 'Ailment' that reduces 'Action speed' for a 'Duration'
	Corruption - A 'Chaos' 'Ailment' that randomly reverses 'Resource' regeneration

	**Impairment**
	Stun - A 'Physical' 'Impairment' that prevents 'Action(s)'
	Panic - A 'Fire' 'Impairment' that forces uncontrolled 'movement' at increased 'movement speed' while continuing to 'burn'				
	Paralyze - A 'Lightning' 'Ailment' interrupts 'action(s)' on 'damage' taken
	Freeze - a 'Cold' 'Impairment' that prevents 'movement' for a 'Duration'	
	Entropy - A 'Chaos' 'Impairment' that reverses all 'Resource' regeneration
			
			
				
// Combat enemy
	Basic enemy - An 'Enemy' that is randomly generated. Can be Normal, uncommon or rare 'Rarity'
	Boss - A powerful 'Enemy' with designed set of 'action(s)' and 'mechanic(s)'
