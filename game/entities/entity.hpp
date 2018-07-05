class Entity {
  public:
    double posX = 0;
    double posY = 0;
    std::string name;

    void render ();
    void spawn (double, double);

    virtual void update (int) = 0;
};
