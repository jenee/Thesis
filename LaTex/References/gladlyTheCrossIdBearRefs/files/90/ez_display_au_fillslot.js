var ez_ad_units = new Array();

function ez_write_tag(d) {
    if(d instanceof Array) {
        ez_ad_units[ez_ad_units.length] = d;
        var ezcmd = "GA_googleFillSlot('"+d[1]+"');";
        return ezcmd;
    }
    else {
        return "1+1";
    }
}
