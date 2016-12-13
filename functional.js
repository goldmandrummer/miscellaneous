function log (arg) {
	document.writeln(arg);
}

function identity (x) {
	return x;
}

function add (a, b) {
	return a + b;
}

function sub (a, b) {
	return a - b;
}

function identityf (arg) {
	return function () {
		return arg;
	}
}

function addf (a) {
	return function (b) {
		return add(a, b);
	}
}

function curry (function, a) {
	return function (b) {
		return function(a,b);
	}
}

function liftf (func) {
	return function (a) {
		return function (b) {
			return func(a,b);
		}
	}
}

// var increment = curry(add, 1);
// var increment1 = addf(1);
// var increment2 = liftf(add);

function reverse (func) {
	return function (a, b) {
		func(b, a);
	}
}

function counter (inp) {
	return {
		next: function () {
			return ++inp;
		},
		prev: function (argument) {
			return --inp;
		}
	}
}

function fibf (a, b) {
	return function () {
		var c = a;
		a = b;
		b += c;
		return a;
	}
}

function addgroup (a) {
	if (a === undefined) return a;

	return function (b) {
		if (b !== undefined) {
			return addgroup(b);
		};
	}
}