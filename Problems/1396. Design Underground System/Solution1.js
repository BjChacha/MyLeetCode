
var UndergroundSystem = function() {
    this.inStation = new Map();
    this.travel = new Map();
};

UndergroundSystem.prototype.checkIn = function(id, stationName, t) {
    if (this.inStation.has(id)) {
        console.log("error");
    } else {
        this.inStation.set(id, [stationName, t]);
    }
};

UndergroundSystem.prototype.checkOut = function(id, stationName, t) {
    if (!this.inStation.has(id)) {
        console.log("error");
    } else {
        let [s, t0] = this.inStation.get(id);
        let key = [s, stationName].join('->');
        if (this.travel.has(key)) {
            let [sum, cnt] = this.travel.get(key);
            this.travel.set(key, [sum + (t - t0), cnt + 1]);
        } else {
            this.travel.set(key, [(t - t0), 1]);
        }
        this.inStation.delete(id);
    }
};

UndergroundSystem.prototype.getAverageTime = function(startStation, endStation) {
    let key = [startStation, endStation].join('->');
    if (this.travel.has(key)) {
        let [sum, cnt] = this.travel.get(key);
        return sum / cnt;
    } else {
        return 0;
    }
};
