class currentProfile{

    enum profileTypes {E_TRAPEZOIDAL, E_SPROFILE};


    profileTypes activeProfileType;
    bool profileActive = false;

    int elapsedTime;
    int finishTime;


    double trapezoidalProfile();
    double SProfile();

    double calculateOutput();

    void profileTask();
};