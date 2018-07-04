// Header
void onKeyDown (GLubyte, GLint, GLint);
void onKeyUp (GLubyte, GLint, GLint);

// Keys
#define KEY_ESC 27
#define KEY_W 119

// Key states
#define KEY_STATE_NONE 0
#define KEY_STATE_DOWN 1
#define KEY_STATE_PRESSED 2
#define KEY_STATE_UP 3

// Keyboard handler
class Keyboard {
  private:
    int keyLength = 256;
    int keyState[256];
  
  public:
    Keyboard();
    bool isKeyDown (int);
    bool isKeyPressed (int);
    void pool ();
    void setState (int, int);
};

Keyboard::Keyboard () {
  pool();
}

void Keyboard::pool () {
  for (int i=0; i < keyLength; i++) {
    keyState[i] = KEY_STATE_NONE;
  }
}

void Keyboard::setState (int keyCode, int _state) {
  if (keyCode < keyLength) {
    keyState[keyCode] = _state;
  }
}

bool Keyboard::isKeyPressed (int keyCode) {
  if (keyCode >= keyLength) {
    return false;
  }
  if (keyState[keyCode] == KEY_STATE_PRESSED) {
    setState(keyCode, KEY_STATE_DOWN);
    return true;
  }

  return false;
}

bool Keyboard::isKeyDown (int keyCode) {
  if (keyCode >= keyLength) {
    return false;
  }

  return keyState[keyCode] == KEY_STATE_DOWN || keyState[keyCode] == KEY_STATE_PRESSED;
}

// Glut callbacks
Keyboard keyboard;

void onKeyDown (GLubyte key, GLint x, GLint y) {
  if (key == KEY_ESC) {
    exit(0);
  }

  if (!keyboard.isKeyPressed(key)) {
    keyboard.setState(key, KEY_STATE_PRESSED);
  }
  else {
    keyboard.setState(key, KEY_STATE_DOWN);
  }
}

void onKeyUp (GLubyte key, GLint x, GLint y) {
  keyboard.setState(key, KEY_STATE_UP);
}
