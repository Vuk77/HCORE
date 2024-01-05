modded class SCR_BaseGameMode : BaseGameMode
{
	override protected void OnGameModeStart()
	{
		super.OnGameModeStart();
		
		SCR_NotificationSenderComponent sender = SCR_NotificationSenderComponent.Cast(GetGame().GetGameMode().FindComponent(SCR_NotificationSenderComponent));
		if (!sender)
			return;
		
		sender.SetKillFeedType(EKillFeedType.FULL);
		sender.SetReceiveKillFeedType(EKillFeedReceiveType.ALLIES_ONLY);
	}
}