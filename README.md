particle.io Photon (formerly spark.io Core)-web-page-html-control
================================









Update: Feb 2017
This site has been tested with students and works fine but I am making a more up-to-date site at 
https://github.com/hpssjellis/particle-photon-raspberry-pi-iot






An installation video of all but the recent stuff is at




https://youtu.be/-CyKv4UC1OA


[![Instructional video](http://img.youtube.com/vi/-CyKv4UC1OA/0.jpg)](https://youtu.be/-CyKv4UC1OA)













Dec 15, 2015

I just added an index.html for http://www.evothings.com (remember that spark-web.ino still needs to be flashed to the photon for a webpage to be able to communicate with it.)




Update Oct 28, 2015
As this reposiotory is getting bloated and badly named since Spark.io has changed to Particle.io and the Spark Core is now gone replaced with the Photon. I have moved this repository to 

https://github.com/hpssjellis/particle-photon-web-page-control




update Oct 15, 2015

Arrgh! An update on the Photon has left this code not working for AnalogRead. It seems that for the new Photon. AnalogRead can not have the pinmode set. I have change the simple-web.ino to reflect this issue. It should work now.

update Oct 13, 2015
PWM send (write) for analog only works with this setup for pins A4, A5. 

DAC1,2 A3 and A6 have some cool direct voltage thing that presently is not working.
Analog read should work on all pins A0 - A7 but it is having some issues.

Digital read and write is doing fine.


update Oct 2015

Oops. simple.html does not allow any read functions to work. Back to the drawing board, I need to make the AJAX base more simple. So I made the AjaxBetter.html file that should be the one everybody uses. It is as easy as it gets while still returning analog or digital read information. Refer to the more complex xtra-ajax-json-slider-polling.html for Polling or a working slider.

Update Sep 7, 2015

Made simple.html since a youtube user wanted an easier version of the webpage that just uses buttons to activate the photon



Example control of the spark core and perhaps photon with a simple html web page 


https://www.youtube.com/watch?v=-CyKv4UC1OA



Dec 12, 2014  Can't really believe that it worked, but it does. You need to find your access token in the spark settings page at the bottom left of your spark IDE screen.

You then need the Core Device ID which is harder to find. You have to go to the core then click on your cores ">" sign beside the flashing blue dot.

Then just call the function you want to activate. Travels at the speed of your connection which can be fast or up to a few seconds.


Wow. Very happy.



Finished Jan 5, 2015



The files are:

1. simple.html (latest update). Much easier webpage for controlling the Photon or Core

1. spark-control-basic-web-page.html Control a spark device using regular html a form, iframe and local storage. 

1. spark-web.ino the spark file that must be flashed to the device

1. useless.ino  the bare essential spark activation but uses up the four possible spark functions. Simple but useless

1. xtra-ajax-json-slider-polling.html   a more advanced much better than the basic web page still only uses javascript and html but is more efficient.

Both HTML files can be loaded onto phonegap build to make Android and iOS Apps that activate spark devices.



Use at your own risk.

By Jeremy Ellis the maker of http://rocksetta.com

twitter @rocksetta



