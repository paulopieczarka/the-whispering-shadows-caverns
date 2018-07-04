
struct Material {
  float ambient[4];
  float diffuse[4];
  float specular[4];
};

void gluUseMaterial (Material mat) {
  glLightfv(GL_LIGHT0, GL_AMBIENT, mat.ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, mat.diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, mat.specular);
}

Material materialBronze = { 
  { 0.2125f, 0.1275f, 0.054f, 1.0f },
  { 0.714f, 0.4284f, 0.18144f, 1.0f },
  { 0.393548f, 0.271906f, 0.166721f, 1.0f }
};

Material materialRuby = {
  { 0.1745f, 0.01175f, 0.01175f, 0.55f },
  {0.61424f, 0.04136f, 0.04136f, 0.55f },
  {0.727811f, 0.626959f, 0.626959f, 0.55f }
};

Material materialGreen = { 
  { 0.0f,0.05f,0.0f,1.0f },
  { 0.4f,0.5f,0.4f,1.0f},
  {0.04f,0.7f,0.04f,1.0f }
};
