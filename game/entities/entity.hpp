#define ENTITY_MOVE_NONE 0
#define ENTITY_MOVE_FORWARD 1
#define ENTITY_MOVE_BACKWARD 2
#define ENTITY_MOVE_LEFT 3
#define ENTITY_MOVE_RIGHT 4

class Entity {
  protected:
    double moveSpeed;
    double moveDistance;
    int moveDirection;

  public:
    Entity();

    double posX;
    double posY;
    double posZ;
    std::string name;

    void render ();
    void spawn (double, double);
    void idleEffect (int);
    void moveEffect (int);
    void rotateEffect (int);
    void entityUpdate (int);
    void move (int);

    virtual void update (int) = 0;
};
