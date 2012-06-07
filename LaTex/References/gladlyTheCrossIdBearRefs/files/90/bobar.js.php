                 

function get_float_bar() {
   $("#bobar").fadeIn(1000, function(){ show_textandimage(); });
   $.cookie("float_bar", "1", {expires:3});
}

function show_textandimage() {
    bar_shown = true;
    
    $("#logoclick").click();
    $('.bartitle').FontEffect({
        outline         : eval(true), // Apply the outline effect
        outlineColor1   : "#760000", // [find contrasting] The upper left  outline color
        outlineColor2   : "", // [outlineColor1] the lower right outline color
        outlineWeight   : eval(3), // 1=light,2=normal,3=bold
        mirror          : eval(false), // Apply the mirror effect
        mirrorColor     : "", // [object color] The color of the reflex
        mirrorOffset    : eval(-10), // The distance from text
        mirrorHeight    : eval(50), // The height of the reflex (perc.)*
        mirrorDetail    : eval(1), // The reflex detail 1=high,2=medium,3=low
        mirrorTLength   : eval(50), // The length of the sfumature (perc.)*
        mirrorTStart    : eval(0.2), // The starting opacity of the reflex (0-1)
        shadow          : eval(true), // Apply the shadow effect
        shadowColor     : "#000000", // The color of the shadow
        shadowOffsetTop : eval(2), // The top offset position (px)
        shadowOffsetLeft: eval(1), // The left offset position (px)
        shadowBlur      : eval(1), // The shadow blur 1=none,2=low,3=high
        shadowOpacity   : eval(0.2), // The opacity of the shadow (0=none,1=all)
        gradient        : eval(false), // Apply the gradient effect
        gradientColor   : "", // The color of the gradient
        gradientPosition: eval(20), // The start position of the gradient (perc.)*
        gradientLength  : eval(50), // The length of the gradient (perc.)*
        gradientSteps   : eval(20), // the steps of the gradient
        hideText        : eval(false) // Hide the source text
    });
    $('.barsubtitle').FontEffect({
        outline         : eval(false), // Apply the outline effect
        outlineColor1   : "", // [find contrasting] The upper left  outline color
        outlineColor2   : "", // [outlineColor1] the lower right outline color
        outlineWeight   : eval(1), // 1=light,2=normal,3=bold
        mirror          : eval(false), // Apply the mirror effect
        mirrorColor     : "", // [object color] The color of the reflex
        mirrorOffset    : eval(-10), // The distance from text
        mirrorHeight    : eval(50), // The height of the reflex (perc.)*
        mirrorDetail    : eval(1), // The reflex detail 1=high,2=medium,3=low
        mirrorTLength   : eval(50), // The length of the sfumature (perc.)*
        mirrorTStart    : eval(0.2), // The starting opacity of the reflex (0-1)
        shadow          : eval(true), // Apply the shadow effect
        shadowColor     : "#000000", // The color of the shadow
        shadowOffsetTop : eval(1), // The top offset position (px)
        shadowOffsetLeft: eval(1), // The left offset position (px)
        shadowBlur      : eval(1), // The shadow blur 1=none,2=low,3=high
        shadowOpacity   : eval(0.5), // The opacity of the shadow (0=none,1=all)
        gradient        : eval(false), // Apply the gradient effect
        gradientColor   : "", // The color of the gradient
        gradientPosition: eval(20), // The start position of the gradient (perc.)*
        gradientLength  : eval(50), // The length of the gradient (perc.)*
        gradientSteps   : eval(20), // the steps of the gradient
        hideText        : eval(false) // Hide the source text
    });
}

var bar_shown = false;

$(document).ready(function() {
    
    $("#bobar").jixedbar();
    $("#bobar_email").focusin(function() { $(this).val(""); });
    $("#bobar").hide();
 
    if($.cookie("show_bar") == 1 || $.cookie("show_bar") == null)
    {
        var float_cook = $.cookie("float_bar");
        var timeout_floater = float_cook != 1 ? 15000 : 1500; 
        setTimeout('get_float_bar()', timeout_floater);
    }
});

function getquerystring(form, lcl_imp_id, did) {

    lcl_imp_id = parseInt(lcl_imp_id);

    var list_id = '418bef438d';
    var email_list_email = form.bobar_email.value;
    var page_url = window.location.href;
    var refer_url = document.referrer;
    var hc_domain_id = did;
    
    qstr = 'list_id=' + escape(list_id)+'&email_list_email='+escape(email_list_email)+'&signup_url='+page_url+'&domain_id='+hc_domain_id+'&refer_url='+refer_url;  // NOTE: no '?' before querystring
    return qstr;
}
 
xmlhttpPost = function(active_form, implementation_id) {
    
    $('#bobar_searchspin').show();
    $('#bobar_submit').hide();
    $('.searchbox_header').hide();
    $('.bar_arrow').hide();
    $('#bobar_email').hide();
    
    var strURL = 'http://www.ezoic.com/pub/process_email_subscribe.php';
    var did = '51';
    var sitelang = 'php';
    
    var domain = document.domain;

    if(domain == "localhost")
    {
        domain = "localhost:8080";
    }

    var full_url = "";
    switch(sitelang)
    {
        case "asp":
            full_url =  "http://"+domain+"/cross_domain.asp?url="+escape(strURL+"?"+getquerystring(active_form, implementation_id, did));
            break;
            
        case "csharp":
            full_url =  "http://"+domain+"/CrossDomain.aspx?url="+encodeURIComponent(strURL+"?"+getquerystring(active_form, implementation_id, did));
            break;
        
        case "php":
        default:
            full_url =  "http://"+domain+"/cross_domain.php?url="+escape(strURL+"?"+getquerystring(active_form, implementation_id, did));
            break;
    }
    
    $.get(full_url, function(data, status, xmlreq) {
    
        var re = /<success\b[^>]*>([\s\S]*?)<\/success>/gm;
        var match;
        match = re.exec(data);
        var subscribe_success = match[1];

        var re = /<user_message\b[^>]*>([\s\S]*?)<\/user_message>/gm;
        var match;
        match = re.exec(data);
        var message = match[1];
        
        eval(handle_email_subscribe_result)(subscribe_success, message);
    
    });
    
    return false;
}

handle_email_subscribe_result = function(success, message) {
    var message_class = success == "true" ? "success message" : "error message";
    message = "<div style='padding-left: 75px; margin-top: 20px;' class='"+ message_class +"'>"+message+"</div>";
    $("#bobar_search").html(message);
}
