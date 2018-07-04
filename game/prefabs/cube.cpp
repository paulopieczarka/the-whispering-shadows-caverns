void drawTile (Vector3f, Vector3f);

void drawCube (Vector3f position, Material material) {
  glPushMatrix();

  glTranslatef(position.x, position.y, position.z);
  gluUseMaterial(material);
  
  glutSolidCube(1);

  glPopMatrix();
}