#include "ray.hpp"

namespace _462 {
    
    Vector3 dir;
    Vector3 up;
    real_t AR;
    
    Vector3 cR;
    Vector3 cU;
    real_t dist;
    Vector3 pos;
    
    Ray::Ray(){}
    
    Ray::Ray(Ray *ray)
    {
        Ray(ray->e, ray->d);
        
        this->depth = ray->depth;
        this->type = ray->type;
        
        this->x = ray->x;
        this->y = ray->y;
        this->color = ray->color;
        
        this->mint = ray->mint;
        this->maxt = ray->maxt;
        this->time = ray->time;
        
        this->isHit = ray->isHit;
    }
    
    Ray::Ray(Vector3 e, Vector3 d)
    {
        this->e = e;
        this->d = d;
        this->mint = 0.f;
        this->maxt = INFINITY;
        this->time = 0.f;
    }
    
    Ray::Ray(Vector3 e, Vector3 d, float start, float end, float time)
    {
        this->e = e;
        this->d = d;
        this->mint = start;
        this->maxt = end;
        this->time = time;
    }
    
    void Ray::init(const Camera& camera)
    {
        dir = camera.get_direction();
        up = camera.get_up();
        AR = camera.get_aspect_ratio();
        cR = cross(dir, up);
        cU = cross(cR, dir);
        pos = camera.get_position();
        dist = tan(camera.get_fov_radians()/2.0);
    }
    
    Vector3 Ray::get_pixel_dir(real_t ni, real_t nj)
    {
        return normalize(dir + dist*(nj*cU + AR*ni*cR));
    }
    
}
