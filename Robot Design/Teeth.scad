
$fs = 0.2;

toothSpacing = 4;

toothHeight = 2;
toothTaper = 30;

toothThickness = 2;

module singleTooth(extraHeight = 0) {

	newToothHeight = toothHeight + extraHeight;

	toothLowerWidth = toothSpacing/2;
	toothUpperWidth = toothLowerWidth + newToothHeight*tan(toothTaper);

	offset(r = ($negative ? 0.2 : 0))
	translate([0, -toothHeight])
	polygon([	[toothLowerWidth/2, 0],
				[-toothLowerWidth/2, 0],
				[-toothUpperWidth/2, newToothHeight],
				[toothUpperWidth/2, newToothHeight]]);
}

module toothRow(n, extraHeight = 0)
	for(i=[-n/2:n/2]) translate([i*toothSpacing, 0]) singleTooth(extraHeight);

module toothRing(n) {
	ringCircumference = n * toothSpacing;

	ringRadius = ringCircumference / 3.14 / 2;

	circle(ringRadius);
	for(i=[0:n]) rotate(i * 360/n) translate([0, -ringRadius]) singleTooth(2);
}


nSegmentLength = 25;
segmentLength = toothSpacing * nSegmentLength;

nQuarterTurnLength 	= 18;
quarterTurnLength 		= toothSpacing * nQuarterTurnLength;

turnRadius 			= 2*quarterTurnLength / 3.14;

trackWidth = 2* turnRadius;

module tooth() {
	linear_extrude(height = toothThickness) singleTooth();
}
module cutoutTooth() {
	rotate([90, 0, 0])
	translate([0, 0, -toothThickness/2 - 0.3])
	linear_extrude(height = toothThickness + 0.6) singleTooth(1, $negative = false);
}


module turnTeeth() {
	for(i=[0:nQuarterTurnLength*4]) rotate([0, 0, 90/nQuarterTurnLength * i])
	translate([0, turnRadius, 0])
	cutoutTooth();
}

module teethStrip() {
	for(i=[-nSegmentLength/2 - 1:nSegmentLength/2]) translate([(i + 0.5) * toothSpacing, 0, 0])
		cutoutTooth();
}

module trackStrip() {
	translate([0, turnRadius, 0]) teethStrip();
	translate([0, -turnRadius, 0]) teethStrip();
}

module trackPlate() {
	difference() {
		translate([-50, -50, -2.252])
		cube([100, 100, 2.252]);

		translate([0, 0, -5]) cylinder(r = turnRadius - 7, h = 10);
		trackStrip();
		rotate([0, 0, 90]) trackStrip();
		turnTeeth();
	}
}


module motorShaft() {
	difference() {
		cylinder(d = 3.4, h = 10);
		translate([0, 15 + 1.1, 0]) cube([30, 30, 30], true);
	}
}

module motorWheel() {
	difference() {
		union() {
			linear_extrude(height = toothThickness - 0.7) offset(r = 0.5) offset(r = -1) toothRing(12);
			cylinder(d = 7, h = 7.3);
		}
		translate([0, 0, -0.1]) motorShaft();
	}
}

trackPlate();
