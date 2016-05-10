#pragma once

#include "ofx2DMappingContentShape.h"

class ofx2DMappingImage : public ofx2DMappingContentShape {

    public:

    ofImage     image;
    string      img_src;

    ofx2DMappingImage() {
        this->image.clear();
        this->img_src = "";
        this->nature = "IMAGE";
    }

    ofx2DMappingImage(const ofx2DMappingImage& obj) : ofx2DMappingContentShape(obj) {
        this->image = obj.image;
        this->img_src = obj.img_src;
    }

    ofPtr<ofx2DMappingObject> clone() const {
        return ofPtr<ofx2DMappingObject>(new ofx2DMappingImage(*this));
    }

    void loadXml(ofxXmlSettings_ptr xml) {
        ofx2DMappingContentShape::loadXml(xml);
        string url = xml->getValue("url", "images/notfound.png");
        loadImage(url);
    }

    virtual void saveXml(ofxXmlSettings_ptr xml) {
        ofx2DMappingContentShape::saveXml(xml);
        xml->addValue("url", img_src);
    }

//    void draw(float w, float h) {

//        if(this->image.isAllocated()) {
//            ofPushMatrix();
//            glMultMatrixf(this->matrix_dst_norm.getPtr());

//            ofSetColor(255);
//            ofFill();

//            this->image.bind();

//                glBegin(GL_QUADS);

//                glTexCoord2f(this->src[0].x*this->image.getWidth(), this->src[0].y*this->image.getHeight());	glVertex3f(0, 0, 0);
//                glTexCoord2f(this->src[1].x*this->image.getWidth(), this->src[1].y*this->image.getHeight());	glVertex3f(w, 0, 0);
//                glTexCoord2f(this->src[2].x*this->image.getWidth(), this->src[2].y*this->image.getHeight());	glVertex3f(w, h, 0);
//                glTexCoord2f(this->src[3].x*this->image.getWidth(), this->src[3].y*this->image.getHeight());	glVertex3f(0, h, 0);

//                glEnd();

//            this->image.unbind();
//            glPopMatrix();
//        }

//    }

    void loadImage(string url) {
        image.clear();
        if(image.load(url)) {
            img_src = url;
            src_width = image.getWidth();
            src_height = image.getHeight();
            setTexture(&image.getTexture());
        }
        else {
            ofLogError("MappingImage::loadImage()", "Could not load " + url + ".");
        }
    }

};
