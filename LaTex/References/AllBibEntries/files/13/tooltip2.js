/*


======================================================================================================

 This script was tested with the following systems and browsers:

 - Windows XP: IE 6, NN 4, NN 7, Opera 7, Firefox 1
 - Mac OS X:   IE 5, Safari 1

 If you use another browser or system, this script may not work for you - sorry.

------------------------------------------------------------------------------------------------------

 USAGE:

 Use the toolTip-function with mouse-over and mouse-out events (see example below).

 - To show a tooltip, use this syntax: toolTip(text, width in pixels, opacity in percent)
   Note: width and opacity are optional

 - To hide a tooltip, use this syntax: toolTip()

------------------------------------------------------------------------------------------------------

 EXAMPLE:

 <a href="#" onMouseOver="toolTip('Just a test', 150)" onMouseOut="toolTip()">some text here</a>

======================================================================================================
*/

  var OP = (navigator.userAgent.indexOf('Opera') != -1) ? true : false;
  var IE = (navigator.userAgent.indexOf('MSIE') != -1 && !OP) ? true : false;
  var GK = (navigator.userAgent.indexOf('Gecko') != -1) ? true : false;
  var NN4 = document.layers;
  var DOM = document.getElementById;

  function TOOLTIP2() {
//----------------------------------------------------------------------------------------------------
// Configuration
//----------------------------------------------------------------------------------------------------
    this.width = 300;                     // width (pixels)
    this.bgColor = '#A0C5EA';             // background color #A0C5EA
    this.textColor = '#505d8d';           // text color #ffffff
    this.borderColor = '#4D4D94';         // border color #4D4D94
    this.opacity = 80;                    // opacity (percent) - doesn't work with all browsers
    this.cursorDistance = 5;              // distance from cursor (pixels)
	this.type = 2;
	
	/*
	background-color: #A0C5EA;
	padding: 6px;
	border: solid 1px #4D4D94;
	color: #ffffff;
	position: absolute;
	z-index: 5;
	margin-top: -7px;
	font-size: 11px;
	display: none;
	width: 300px;
	font-weight: bold;
	font-family: Trebuchet, Tahoma, Verdana, Arial, Helvetica, sans-serif;
	
	*/

    // don't change
    this.text = '';
    this.height = 0;
    this.obj = 0;
    this.sobj = 0;
    this.active = false;

// -------------------------------------------------------------------------------------------------------
// Functions
// -------------------------------------------------------------------------------------------------------
    this.create = function() {
	  
	    //If tooltip 1 then this style
   		if(this.type == 1) {		
			this.bgColor = '#FFFFC0';             // background color
        	this.borderColor = '#D00000';         // border color
			var sClass = 'toolTip1';
			var sAlign = 'center';
		
		//if tooltop 2 then this style
		}else if (this.type == 2) {
	    	this.bgColor = '#e3ebf5';             // background color #A0C5EA
    		this.borderColor = '#505d8d';		// border color #4D4D94 
			this.textColor = '#505d8d';
			var sClass = 'toolTip2';
			var sAlign = 'center';
	
	//if tooltop 3 then this style
		}else if (this.type == 3) {
	    	this.bgColor = '#A0C5EA';             // background color
    		this.borderColor = '#a6b5c7';         // border color
			var sClass = 'toolTip3';
			var sAlign = 'left';
        }
	  
	  if(!this.sobj) this.init();

      var t = '<table border=0 cellspacing=0 cellpadding=4 width=' + this.width + ' bgcolor=' + this.bgColor + '><tr>' +
              '<td align=' + sAlign + ' class=' + sClass + '>' + this.text + '</td></tr></table>';
			  //alert(t);

      if(NN4) {
        t = '<table border=0 cellspacing=0 cellpadding=1><tr><td bgcolor=' + this.borderColor + '>' + t + '</td></tr></table>';
        this.sobj.document.write(t);
        this.sobj.document.close();
      }
      else {
        this.sobj.border = '1px solid ' + this.borderColor;
        this.setOpacity();
        if(document.getElementById) document.getElementById('ToolTip2').innerHTML = t;
        else document.all.ToolTip2.innerHTML = t;
      }
      if(DOM) this.height = this.obj.offsetHeight;
      else if(IE) this.height = this.sobj.pixelHeight;
      else if(NN4) this.height = this.obj.clip.bottom;

      this.show();
    }

    this.init = function() {
      if(DOM) {
        this.obj = document.getElementById('ToolTip2');
        this.sobj = this.obj.style;
      }
      else if(IE) {
        this.obj = document.all.ToolTip2;
        this.sobj = this.obj.style;
      }
      else if(NN4) {
        this.obj = document.ToolTip2;
        this.sobj = this.obj;
      }
    }

    this.show = function() {
      var ext = (document.layers ? '' : 'px');
      var left = mouseX;
      var top = mouseY;
	  
	  //alert('mouseX :' + mouseX + ' ,mouseY :' + mouseY);

      if(left + this.width + this.cursorDistance > winX) left -= this.width + this.cursorDistance;
      else left += this.cursorDistance;

      if(top + this.height + this.cursorDistance - scrTop > winY) top -= this.height;
      else top += this.cursorDistance;
	  
	  if(left<0) left = 5;

      this.sobj.left = left + ext;
      this.sobj.top = top + ext;
	  
	  //alert('this.sobj.left : ' +  this.sobj.left + ' this.sobj.top :' + this.sobj.top)

      if(!this.active) {
        this.sobj.visibility = 'visible';
        this.active = true;
      }
    }

    this.hide = function() {
      if(this.sobj) this.sobj.visibility = 'hidden';
      this.active = false;
    }

    this.setOpacity = function() {
      this.sobj.filter = 'alpha(opacity=' + this.opacity + ')';
      this.sobj.mozOpacity = '.1';
      if(this.obj.filters) this.obj.filters.alpha.opacity = this.opacity;
      if(!document.all && this.sobj.setProperty) this.sobj.setProperty('-moz-opacity', this.opacity / 100, '');
    }
  }

//----------------------------------------------------------------------------------------------------
// Build layer, get mouse coordinates and window width, create tooltip-object
//----------------------------------------------------------------------------------------------------
  var tooltip2 = mouseX = mouseY = winX = winY = scrTop = 0;

  if(document.layers) {
    document.write('<layer id="ToolTip2"></layer>');
    document.captureEvents(Event.MOUSEMOVE);
  }
  else document.write('<div id="ToolTip2" style="position:absolute; z-index:299"></div>');
  document.onmousemove = getMouseXY;

  function getMouseXY(e) {
    if(document.all)e = event;
	
    if(document.body && document.body.scrollTop >= 0) scrTop = document.body.scrollTop;
    else if(window.pageYOffset >= 0) scrTop = window.pageYOffset;

    if(IE) {

		if  (document.body && typeof document.body.scrollLeft != 'undefined' && typeof e.clientX != 'undefined'){
      	   mouseX = event.clientX + document.body.scrollLeft;
		   mouseY = event.clientY + document.body.scrollTop;
		}else if (typeof document.documentElement.scrollLeft != 'undefined' && typeof e.clientX != 'undefined'){
		   mouseX = event.clientX + document.documentElement.scrollLeft;
		   mouseY = event.clientY + document.documentElement.scrollTop;
		}	 
    }
    else {
      mouseX = e.pageX;
      mouseY = e.pageY;
    }

    if(mouseX < 0) mouseX = 0;
    if(mouseY < 0) mouseY = 0;

    if(GK || NN4) {
      winX = window.innerWidth - 25;
      winY = window.innerHeight;
    }
    else if(DOM) {
	  
	  if ((document.body) && (typeof document.body.offsetWidth != 'undefined') && (typeof document.body.offsetHeight != 'undefined')){
      	  winX = document.body.offsetWidth - 25;
      	  winY = document.body.offsetHeight;
	  }else{
	  	  winX = 100;
      	  winY = 100;
	  }
    }
    else {
      winX = screen.width - 25;
      winY = screen.height;
    }
	//alert('winX :' + winX + ' , winY :' + winY);
    if(tooltip2 && tooltip2.active) tooltip2.show();
  }

  function toolTip2(text, width, opacity, type) {
    if(text) {
      tooltip2 = new TOOLTIP2();
      tooltip2.text = text;
      if(width) tooltip2.width = width;
      if(opacity) tooltip2.opacity = opacity;
	  if(type) tooltip2.type = type;
      tooltip2.create();
    }
    else if(tooltip2) tooltip2.hide();
  }

