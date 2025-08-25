package br.edu.unifei.ecot12.finalproject.xogunatotokugawa;

public class Fief {
	
	private String location;
	private String name;
	
	private Edo_Society daimyo;
	
	private Four_Classes peasants;
	
	public Fief(Edo_Society daimyo, Four_Classes peasants) {
        this.daimyo = daimyo;
        this.peasants = peasants;
    }
	
	public String getLocation() {
		return location;
	}

	public void setLocation(String location) {
		this.location = location;
	}

	public Edo_Society getDaimyo() {
		return daimyo;
	}

	public void setDaimyo(Edo_Society daimyo) {
		this.daimyo = daimyo;
	}

	public Four_Classes getPeasants() {
		return peasants;
	}

	public void setPeasants(Four_Classes peasants) {
		this.peasants = peasants;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	};
	
	

}
