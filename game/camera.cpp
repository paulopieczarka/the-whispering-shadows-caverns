class Camera {
  private:
    double x = 0.0;
    double y = 0.0;

  public:
    void onRender (Dimension);
    void setPosition (double, double);

    double getPosX ();
    double getPosY ();
};

void Camera::setPosition (double _x, double _y) {
  x = _x;
  y = _y;
};

void Camera::onRender (Dimension window) {
	glTranslatef(x, y, 0.0f);
};

double Camera::getPosX () {
  return x;
};

double Camera::getPosY () {
  return y;
};
