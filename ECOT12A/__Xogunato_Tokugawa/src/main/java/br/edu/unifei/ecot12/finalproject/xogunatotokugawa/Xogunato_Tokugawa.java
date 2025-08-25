package br.edu.unifei.ecot12.finalproject.xogunatotokugawa;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

public class Xogunato_Tokugawa {
	
	private Calendar startPeriod;
	private Calendar endPeriod;
	
	private Edo_Society xogum;
	private Edo_Society emperor;
	private List<Court_Nobility> courtNobility = new ArrayList<Court_Nobility>();
	private List<Daimyo> daimyo = new ArrayList<Daimyo>();
	private List<Samurai> samurai = new ArrayList<Samurai>();
	private List<Merchants> merchants = new ArrayList<Merchants>();
	private List<Artisans> artisians = new ArrayList<Artisans>();
	private List<Peasants> peasants = new ArrayList<Peasants>();
	
	private Social_Policy socialPolicy;
	
	public Xogunato_Tokugawa(Edo_Society xogum, Edo_Society emperor,
            List<Court_Nobility> courtNobilityList, List<Daimyo> daimyoList,
            List<Samurai> samuraiList, List<Merchants> merchantsList,
            List<Artisans> artisansList, List<Peasants> peasants,
            Social_Policy socialPolicy) {
		
			this.xogum = xogum;
			this.emperor = emperor;
			this.courtNobility = courtNobilityList;
			this.daimyo = daimyoList;
			this.samurai = samuraiList;
			this.merchants = merchantsList;
			this.artisians = artisansList;
			this.peasants = peasants;
			this.socialPolicy = socialPolicy;
}

	public Calendar getStartPeriod() {
		return startPeriod;
	}

	public void setStartPeriod(Calendar startPeriod) {
		this.startPeriod = startPeriod;
	}

	public Calendar getEndPeriod() {
		return endPeriod;
	}

	public void setEndPeriod(Calendar endPeriod) {
		this.endPeriod = endPeriod;
	}

	public Edo_Society getXogum() {
		return xogum;
	}

	public void setXogum(Edo_Society xogum) {
		this.xogum = xogum;
	}

	public Edo_Society getEmperor() {
		return emperor;
	}

	public void setEmperor(Edo_Society emperor) {
		this.emperor = emperor;
	}

	public List<Court_Nobility> getCourtNobility() {
		return courtNobility;
	}

	public void setCourtNobility(List<Court_Nobility> courtNobility) {
		this.courtNobility = courtNobility;
	}

	public List<Daimyo> getDaimyo() {
		return daimyo;
	}

	public void setDaimyo(List<Daimyo> daimyo) {
		this.daimyo = daimyo;
	}

	public List<Samurai> getSamurai() {
		return samurai;
	}

	public void setSamurai(List<Samurai> samurai) {
		this.samurai = samurai;
	}

	public List<Merchants> getMerchants() {
		return merchants;
	}

	public void setMerchants(List<Merchants> merchants) {
		this.merchants = merchants;
	}

	public List<Artisans> getArtisians() {
		return artisians;
	}

	public void setArtisians(List<Artisans> artisians) {
		this.artisians = artisians;
	}

	public List<Peasants> getPeasants() {
		return peasants;
	}

	public void setPeasants(List<Peasants> peasants) {
		this.peasants = peasants;
	}

	public Social_Policy getSocialPolicy() {
		return socialPolicy;
	}

	public void setSocialPolicy(Social_Policy socialPolicy) {
		this.socialPolicy = socialPolicy;
	}
	

    

}
