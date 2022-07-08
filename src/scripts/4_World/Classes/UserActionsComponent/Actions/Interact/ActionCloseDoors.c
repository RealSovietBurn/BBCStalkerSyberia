modded class ActionCloseDoors
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (super.ActionCondition(player, target, item))
		{
			House house;
			if ( Class.CastTo(house, target.GetObject()) )
			{
				int doorIndex = house.GetDoorIndex(target.GetComponentIndex());
				if (doorIndex != -1)
				{
					BuildingLivespace livespace = BuildingLivespace.Find(house, house.GetDoorSoundPos(doorIndex));
					if (livespace && !livespace.CanCloseDoor(player, doorIndex))
					{
						return false;
					}
				}
			}
			
			return true;
		}
		
		return false;
	}
};