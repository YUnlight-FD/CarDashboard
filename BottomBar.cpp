#include "BottomBar.h"
BottomBar::BottomBar(){}
BottomBar::~BottomBar(){}
void BottomBar::setBackgroundColor(GLfloat r,GLfloat g,GLfloat b){
	this->BG_R = r;
	this->BG_G = g;
	this->BG_B = b;
}

void BottomBar::setPosition(GLint px,GLint py){
	this->cx = px;
	this->cy = py;
}

void BottomBar::drawBottomBar(){
	GLfloat px = this->cx;
	GLfloat py = this->cy;
	
	//BorderLine
	glPushMatrix();
		glColor3f(1,1,1);
		drawLine(px-400,py-149,px-328,py-49,5);
		drawLine(px-328,py-49,px-230,py-49,5);
		drawLine(px-230,py-49,px-168,py-109,5);
		drawLine(px-168,py-109,(px*2)-140,py-109,4);
		drawLine((px*2)-140,py-109,(px*2)-198,py-149,4);
		drawLine((px*2)-198,py-149,px-400,py-149,3);
	glPopMatrix();
	glLoadIdentity();
	
	//Bottom bar
	glPushMatrix();
	glBegin(GL_POLYGON);
		glColor3f(this->BG_R,this->BG_G,this->BG_B);
		glVertex3f(px-400,py-149,0);
		glVertex3f(px-328,py-49,0);
		glVertex3f(px-230,py-49,0);
		glVertex3f(px-168,py-109,0);
		glVertex3f((px*2)-140,py-109,0);
		glVertex3f((px*2)-198,py-149,0);
		glVertex3f(px-400,py-149,0);
	glEnd();
	glPopMatrix();
	glLoadIdentity();
}
void BottomBar::drawSpeedText(){
	
	GLint cx = this->cx-290;
	GLint cy = this->cy-112;
	glColor3f(1,1,1);
	glPushMatrix();
	
		//1
		drawRect(cx-27,cy+25,10,6);
		drawRect(cx-22,cy-1,5,34);
		
		
		//drawRect(cx,cy,5,30);
		
		
		//2
		setBorderColor(this->BG_R,this->BG_G,this->BG_B);
		setFilledColor(1,1,1);
		setUnfilledColor(this->BG_R,this->BG_G,this->BG_B);
		rotate(180, cx,cy);
		drawRingedCircle(15,cx-5,cy-22, 2, 0.5f, 8);
		
		glColor3f(1,1,1);
		rotate(45,cx-14,cy-25);
		drawRect(cx-14,cy-25,28,5);
		glLoadIdentity();
		drawRect(cx-7,cy,25,5);
		
		
		//Zero
		
		drawEllipse(cx+37,cy+17, 13.5f, 19.0f);
		glColor3f(this->BG_R,this->BG_G,this->BG_B);
		drawEllipse(cx+37,cy+17, 7.5f, 14.0f);
		
	glPopMatrix();
	glLoadIdentity();
}
void BottomBar::draw(){
	drawBottomBar();
	drawSpeedText();
}
