
void drawTile (Vector3f position, Material material) {
  glPushMatrix();

  gluUseMaterial(material);
  glTranslatef(position.x, position.y, position.z-.5);
  glScalef(.98, .98, .1);
  glutSolidCube(1);


  glPopMatrix();
}
