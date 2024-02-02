modded class SCR_CharacterCameraHandlerComponent
{
    override int CameraSelector()
    {
        if (m_OwnerCharacter.IsInVehicle())
        {
            CompartmentAccessComponent compartmentAccess = m_OwnerCharacter.GetCompartmentAccessComponent();
            Vehicle vehicle = Vehicle.Cast(compartmentAccess.GetVehicleIn(m_OwnerCharacter));
            BaseCompartmentSlot currentCompartment = compartmentAccess.GetCompartment();

            // Check if current compartment is Cargo
            if (currentCompartment && currentCompartment.GetType() == ECompartmentType.Cargo)
            {
                // Force fp for characters in cargo (like transport)
                SetThirdPerson(false);
                return CharacterCameraSet.CHARACTERCAMERA_1ST_VEHICLE;
            }

            // Check if vehicle is in whitelist for tp
            string vehicleType = vehicle.ClassName();
            if (IsVehicleInWhitelist(vehicleType))
            {
                // Allow tp for whitelisted vehicles
                SetThirdPerson(true);
                return CharacterCameraSet.CHARACTERCAMERA_3RD_VEHICLE;
            }
        }
        else
        {
            // If not in veh, force fp
            SetThirdPerson(false);
            return CharacterCameraSet.CHARACTERCAMERA_1ST;
        }

        // For any others, default behavior
        return super.CameraSelector();

    };
    
    bool IsVehicleInWhitelist(string vehicleType)
    {
        // Define whitelist
        array<string> vehicleWhitelist = {"Example_Vehicle1", "Example_Vehicle2"};
        return vehicleWhitelist.Contains(vehicleType);
    }
};
