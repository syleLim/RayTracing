# RayTracing

## Object
Create Ray Tracing model

## Environment
### C Programing
OS : mac os (for minilibx)
※ minilibx is x-window program for mac os. if you want to run it with ubuntu, you have to download for minilibx for ubuntu.

Command : `make all`

### JS
OS : ubuntu 18.04 / nodeJS v12.18.0

Command : `node test.js`

## RayTracing
RayTracing is one of visualization method for object in space.<br><br><br>it composed Camera, Light, Objects.<br>Camera is view point, it consist of position and direction, up.<br><br>Light is light source in space.<br>It is four types, point, directional, ambient, emmesive. but we use point and ambient. point light is consist of position, intensity, color.<br><br>Objects are somethig for showing. any possible like polygons, but we use 5 objects (sphere, plane, square, triangle, cylinder). they are commonly consist of position. and each objects have own elements.(for example, sphere has radius)
 
<br><br>