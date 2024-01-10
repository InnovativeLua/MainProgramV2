class motionProfile{

    enum profileTypes {E_TRAPEZOIDAL, E_SPROFILE};


    profileTypes activeProfileType;
    bool profileActive = false;

    int elapsedTime;
    int finishTime;

    double accelTime; //Time it takes to reach max speed
    double maxSpeed;


    double trapezoidalProfile();
    double SProfile();

    double calculateOutput();

    void profileTask();
};