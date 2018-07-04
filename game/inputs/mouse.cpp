// Mouse button keys
#define MOUSE_LEFT_BUTTON 0
#define MOUSE_MIDDLE_BUTTON 1
#define MOUSE_RIGHT_BUTTON 2

// Mouse button states
#define BUTTON_STATE_NONE 0
#define BUTTON_STATE_PRESSED 1
#define BUTTON_STATE_UP 2
#define BUTTON_STATE_DOWN 3

// Mouse handler
class Mouse {
  private:
    int buttonLength = 3;
    int buttonState[3];

  public:
    double posX;
    double posY;

    Mouse ();
    void setPosition (int, int);
    void pool ();
    void setButtonState (int, int);
    bool isButtonPressed (int);
    bool isButtonDown (int);
};

Mouse::Mouse () {
  pool();
}

void Mouse::pool () {
  for (int i=0; i < buttonLength; i++) {
    buttonState[i] = BUTTON_STATE_NONE;
  }
}

void Mouse::setPosition (int _x, int _y) {
  posX = (double)_x;
  posY = (double)_y;
}

void Mouse::setButtonState (int button, int state) {
  if (button < buttonLength) {
    buttonState[button] = state;
  }
}

bool Mouse::isButtonPressed (int button) {
  if (button >= buttonLength) {
    return false;
  }

  if (buttonState[button] == BUTTON_STATE_PRESSED) {
    buttonState[button] = BUTTON_STATE_DOWN;
    return true;
  }

  return false;
}

bool Mouse::isButtonDown (int button) {
  if (button >= buttonLength) {
    return false;
  }

  return buttonState[button] == BUTTON_STATE_PRESSED || buttonState[button] == BUTTON_STATE_DOWN;
}

// Glut callbacks
Mouse mouse;

void onMouseMove (int x, int y) {
  mouse.setPosition(x, y);
}

void onMouseDrag (int x, int y) {
  onMouseMove(x, y);
}

void onMouseClick (int button, int state, int x, int y) {
  if (state == GLUT_UP) {
    mouse.setButtonState(button, BUTTON_STATE_UP);
  }
  else if (state == GLUT_DOWN) {
    mouse.setButtonState(button, BUTTON_STATE_PRESSED);
  }
}