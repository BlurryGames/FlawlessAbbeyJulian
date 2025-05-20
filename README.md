# FlawlessAbbeyJulian

Instructions
	World Scene requirements
		Game Mode: BP_GameMode
		Player Controller: BP_PlayerController
		Default Pawn: BP_Player

		WARNING: Setup just in case you need or want to create other scene, if you don't, you can simply load the 
		world scene in "\Content\Test\Maps\TestMap"

	Input
		I: Open / Close inventory UI
		Mouse Drag: Move Slot / Rotate 3D Object
		Mouse Wheel: Zoom object
		Left click: Only over an Actor Trigger dialogue if it's NPC / Pickup if it's item
		Space Bar: Skip dialogue text
		Enter: Close dialogue UI

	Add NPC and dialogue
		Set a new enum for the NPC in "\Source\FlawlessAbbeyJulian\Public\DialogueType.h", add that enum and its name 
		to the map "DialogueNameMap" inside "\Source\FlawlessAbbeyJulian\Public\UIUtilityLibrary.h", use the data 
		table "\Content\Test\Blueprints\Data\DT_Dialogue" to create a row, and also enter the NPC name and dialogue. 
		Derive a Blueprint from "BaseNPC", choose the mesh for that NPC in Blueprint editor, set corresponding 
		Dialogue enum in "DialogueType" variable, and place it in the world.

	Add Item
		Set a new enum for the item in "\Source\FlawlessAbbeyJulian\Public\ItemType.h", add that enum and its name 
		to the map "ItemNameMap" inside "\Source\FlawlessAbbeyJulian\Public\UIUtilityLibrary.h". You need to create 
		a "RenderTarget", derive a material of the same render target and establish it for UI. Use the data table 
		"\Content\Test\Blueprints\Data\DT_Item" to create a row, and also enter the item name, description, icon 
		(Texture2D), material (The render target you has created for this item).

		Derive a Blueprint from "BaseItem", choose the mesh for that NPC in Blueprint editor, set the desired Render 
		Target in Capture component, set corresponding item enum in "ItemType" variable, and place it in the world. 
		You can customize the positions and rotations of the "Mesh" and "Capture" component to be where you want, you 
		can also customize the "HiddingPosition" and "ZoomLimit" variables according to what you need for that 
		functionality.

	Add Slot (Complete the previous section "Add Item" first)
		Add a widget of the "WB_Slot" type within the inventory in 
		"\Content\Test\Blueprints\UserInterface\WB_Inventory" widget, set corresponding item enum in "ItemType" 
		variable, customize that slot and others within the inventory space.

	Change text speed
		In "\Content\Test\Blueprints\UserInterface\WB_Dialogue" Widget modify the variable "WordsDelay" to the 
		desired value.

	Change interaction sensitivity
		In "\Content\Test\Blueprints\UserInterface\WB_Inspect" Widget modify the variable "InspectionSensitivity" to 
		the desired value.
		

	WARNING: Any name written in the item and dialog maps must be exactly the same as the name of the corresponding row 
	within the item or dialog data table.

Design patterns

	Singleton
		Since it seems to me a good practice to reduce human errors I decided to use enums for items and dialogues, I 
		made two Data Table respectively with its relevant structure, this could already be considered "Singleton" so 
		that the Unreal Data Table involves. The problem is that to access the rows of these, you need to write in the 
		name of the row you want. Then to take advantage of the enums I made a library "uiutilitylibary.h" accessible 
		from Blueprints to request the name corresponding to the desired row giving the related enum.

	Pool Object
		This is the design pattern that I consider most useful for video games, since almost everything goes in the 
		execution time and in the case of Unreal that has an integrated garbage collector it is very difficult to control 
		resources. What I did is that any actor or widget are assigned or created from the first moment, while they are 
		reused or executed logic when necessary.

	Mediator / Observer
		This is a design pattern that Unreal is already given without having to do anything. Classes such as "Game Mode" 
		and "Player Controller" are practically an example of this. The only remarkable thing was that I use the 
		"BP_playerController" to subscribe events in order to listen to the user's inputs and execute these events of the 
		relevant objects during those inputs.

	Chain of responsibility
		Specifically during the interactions involving the mouse drag within the UI I implemented that relevant data were 
		passed through the class "BP_Dragdrop", so that the different widgets involved could receive and use what they 
		required and when they require it.
