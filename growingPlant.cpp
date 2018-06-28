int growingPlant(int upSpeed, int downSpeed, int desiredHeight) {
    /*
    Each day a plant is growing by upSpeed meters. Each night that 
    plant's height decreases by downSpeed meters due to the lack of sun 
    heat. Initially, plant is 0 meters tall. We plant the seed at the 
    beginning of a day. We want to know when the height of the plant will 
    reach a certain level.

    Example

    For upSpeed = 100, downSpeed = 10 and desiredHeight = 910, the output should be
    growingPlant(upSpeed, downSpeed, desiredHeight) = 10.
    */
    
    int current_height{ 0 }, days{ 0 };
    
    while (current_height < desiredHeight)
    {
        current_height += upSpeed;
        if (current_height >= desiredHeight)
            return days + 1;
        current_height -= downSpeed;
        days++;
    }
     return days - 1;
}
