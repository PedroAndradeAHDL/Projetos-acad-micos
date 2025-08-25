package br.edu.unifei.ecot12.finalproject.xogunatotokugawa;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

public class App {

	public static void main(String[] args) {
		
		// Instanciando calendario
		Calendar c = Calendar.getInstance();
		
		// Instanciando as religioes
		Religion christianity = new Christianity();
		Religion buddReligion = new Buddhism();
		Religion shintReligion = new Shintoism();
		
		// Instanciando a politica social
		Social_Policy social_policy = new Sakoku();
		social_policy.setObjective("isolar a sociedade japonesa do mundo externo");
		c.set(c.YEAR, 1639);
		social_policy.setStartPeriod(c);
		c.set(c.YEAR, 1853);
		social_policy.setEndPeriod(c);
		social_policy.setForeigTrade(false);
		social_policy.setShogunatoName("Tokugawa Ieyasu");
		social_policy.toggleChristianity();
		
		// Imprimindo política social
		System.out.println("A política de Sakoku começou em " + social_policy.getStartPeriod().get(Calendar.YEAR) + 
				" com o objetivo de " + social_policy.getObjective() + ".");
		System.out.println("Ela durou até " + social_policy.getEndPeriod().get(Calendar.YEAR) + 
				" e foi implementada pelo xogum " + social_policy.getShogunatoName() + ".");
		
		// Instanciando o Xogum
		Edo_Society xogum = Xogum.getXogum();
		xogum.setName("Tokugawa Ieyasu");
		c.set(c.YEAR, 1543);
		xogum.setBirth(c);
		c.set(c.YEAR, 1616);
		xogum.setDeath(c);
		xogum.setPoliticalInfluecne(true);
		xogum.setSocialInfluence(true);
		xogum.setPoliticalReputation("Excepcional");
		Xogum.getXogum().setFamily("Tokugawa");
		c.set(c.YEAR, 1603);
		Xogum.getXogum().setReignStart(c);
		c.set(c.YEAR, 1616);
		Xogum.getXogum().setReignEnd(c);
		xogum.setReligion(social_policy.getBuddhism());
		xogum.setPoliticalInfluecne(true);

		
		// Imprimindo detalhes do xogum
		System.out.println("O xogum " + xogum.getName() + " nasceu em " + xogum.getBirth().get(Calendar.YEAR) + 
				" e faleceu em " + xogum.getDeath().get(Calendar.YEAR) + ".");
		System.out.println("Ele começou seu reinado em " + Xogum.getXogum().getReignStart().get(Calendar.YEAR) + 
				" e terminou em " + Xogum.getXogum().getReignEnd().get(Calendar.YEAR) + ".");
		System.out.println("Sua influência política era " + (xogum.isPoliticalInfluecne() ? "significativa" : "insignificante") + 
				" e sua reputação política era " + xogum.getPoliticalReputation() + ".");
		
		// Instanciando o Imperador
		Edo_Society emperor = Emperor.getEmperor();
		emperor.setName("Go-Yozei");
		c.set(c.YEAR, 1586);
		emperor.setBirth(c);
		c.set(c.YEAR, 1611);
		emperor.setDeath(c);
		emperor.setPoliticalInfluecne(false);
		emperor.setSocialInfluence(true);
		Emperor.getEmperor().setDynasty("Yamato");
		Emperor.getEmperor().setImperialHouse("Yamato");
		Emperor.getEmperor().setXogum(Xogum.getXogum());
		emperor.setReligion(social_policy.getBuddhism());
		
		// Imprimindo detalhes do imperador
		System.out.println("O imperador " + emperor.getName() + " nasceu em " + emperor.getBirth().get(Calendar.YEAR) + 
				" e faleceu em " + emperor.getDeath().get(Calendar.YEAR) + ".");
		System.out.println("Ele pertencia à dinastia " + Emperor.getEmperor().getDynasty() + " e à casa imperial " + Emperor.getEmperor().getImperialHouse() + ".");
		System.out.println("Sua influência política era " + (emperor.isPoliticalInfluecne() ? "significativa" : "insignificante") + 
				", mas tinha uma grande influência social.");
		
		// Instanciando o palácio imperial
		ImperialPalace imperialPalace = new ImperialPalace();
		imperialPalace.setLocation("Tokyo - Chiyoda");
		imperialPalace.setEmperor(Emperor.getEmperor());
		
		// Imprimindo detalhes do palácio imperial
		System.out.println("O palácio imperial está localizado em " + imperialPalace.getLocation() + 
				" e é a residência do imperador " + imperialPalace.getEmperor().getName() + ".");
		
		// Instanciando nobre da corte
		Court_Nobility courtNobility = new Court_Nobility();
		courtNobility.setName("Konoe Nobutada");
		c.set(c.YEAR, 1565);
		courtNobility.setBirth(c);
		c.set(c.YEAR, 1614);
		courtNobility.setDeath(c);
		courtNobility.setPoliticalInfluecne(true);
		courtNobility.setSocialInfluence(true);
		courtNobility.setPoliticalReputation("Muito boa");
		courtNobility.setResidence("Kyoto");
		courtNobility.setReligion(social_policy.getBuddhism());
		List<Court_Nobility> courtNobilityList = new ArrayList<Court_Nobility>();
		courtNobilityList.add(courtNobility);
		
		// Imprimindo detalhes do nobre da corte
		System.out.println("O nobre da corte " + courtNobility.getName() + " nasceu em " + courtNobility.getBirth().get(Calendar.YEAR) + 
				" e faleceu em " + courtNobility.getDeath().get(Calendar.YEAR) + ".");
		System.out.println("Ele residia em " + courtNobility.getResidence() + 
				" e tinha uma reputação política " + courtNobility.getPoliticalReputation() + ".");
		
		// Instanciando Daimyo
		Daimyo daimyo = new Daimyo();
		daimyo.setName("Date Masamune");
		c.set(c.YEAR, 1567);
		daimyo.setBirth(c);
		c.set(c.YEAR, 1636);
		daimyo.setDeath(c);
		daimyo.setPoliticalInfluecne(true);
		daimyo.setSocialInfluence(true);
		daimyo.setPoliticalReputation("Muito boa");
		daimyo.setClan("Date");
		daimyo.setTerritory("Sendai, Tohoku");
		daimyo.setCastleName("Sendai-jo Castle");
		daimyo.setRoyalConstructors(new RoyalConstructors());
		daimyo.setRoyalConstructors(new ReligiousConstructors());
		daimyo.setRoyalConstructors(new Botanicals());
		daimyo.setReligion(social_policy.getBuddhism());
		List<Daimyo> daimyoList = new ArrayList<Daimyo>();
		daimyoList.add(daimyo);
		
		// Imprimindo detalhes do Daimyo
		System.out.println("O Daimyo " + daimyo.getName() + " nasceu em " + daimyo.getBirth().get(Calendar.YEAR) + 
				" e faleceu em " + daimyo.getDeath().get(Calendar.YEAR) + ".");
		System.out.println("Ele governava o território de " + daimyo.getTerritory() + 
				" e residia no castelo " + daimyo.getCastleName() + ".");
		
		// Instanciando as quatro classes
		Samurai samurai = new Samurai();
		samurai.setName("Katakura Kojūrō");
		c.set(c.YEAR, 1561);
		samurai.setBirth(c);
		c.set(c.YEAR, 1615);
		samurai.setDeath(c);
		samurai.setPoliticalInfluecne(false);		
		samurai.setSocialInfluence(true);
		samurai.setLocalReputation("Excepcional");
		samurai.setDaimyoLord(daimyo);
		List<Samurai> samuraiList = new ArrayList<Samurai>();
		samuraiList.add(samurai);
		
		// Imprimindo detalhes do Samurai
		System.out.println("O samurai " + samurai.getName() + " nasceu em " + samurai.getBirth().get(Calendar.YEAR) + 
				" e faleceu em " + samurai.getDeath().get(Calendar.YEAR) + ".");
		System.out.println("Ele tinha uma reputação local " + samurai.getLocalReputation() + 
				" e grande influência social.");
		
		// Instanciando um feudo
		Fief fief = new Fief(daimyo, samurai);
		fief.setLocation("Tohoku");
		fief.setName("Sendai");
		
		// Imprimindo detalhes do feudo
		System.out.println("O feudo de " + fief.getName() + " está localizado em " + fief.getLocation() + 
				" e é governado pelo Daimyo " + daimyo.getName() + ".");
		System.out.println("Um dos samurais notáveis deste feudo é " + samurai.getName() + ".");
		
		// Instanciando uma lista de comerciantes
		List<Merchants> merchantsList = new ArrayList<Merchants>();
		Merchants merchant = new Merchants();
		merchant.setName("Yodoya Keian");
		merchantsList.add(merchant);
		
		// Instanciando uma lista de artesãos
		List<Artisans> artisansList = new ArrayList<Artisans>();
		Artisans artisan = new Artisans();
		artisan.setName("Honami Koetsu");
		artisansList.add(artisan);
		
		// Instanciando uma lista de camponeses
		List<Peasants> peasantsList = new ArrayList<Peasants>();
		Peasants peasant = new Peasants();
		peasant.setName("Saigo Takamori");
		peasantsList.add(peasant);
		
		// Instanciando Xogunato_Tokugawa
		Xogunato_Tokugawa xogunatoTokugawa = new Xogunato_Tokugawa(
				xogum, emperor, courtNobilityList, daimyoList, samuraiList, 
				merchantsList, artisansList, peasantsList, social_policy);
		
		// Imprimindo detalhes do Xogunato_Tokugawa
		System.out.println("Xogunato Tokugawa:");
		System.out.println("Xogum: " + xogunatoTokugawa.getXogum().getName());
		System.out.println("Imperador: " + xogunatoTokugawa.getEmperor().getName());
		
		System.out.println("Nobres da Corte:");
		for (Edo_Society noble : xogunatoTokugawa.getCourtNobility()) {
			System.out.println("  - " + noble.getName());
		}
		
		System.out.println("Daimyos:");
		for (Edo_Society d : xogunatoTokugawa.getDaimyo()) {
			System.out.println("  - " + d.getName());
		}
		
		System.out.println("Samurais:");
		for (Edo_Society s : xogunatoTokugawa.getSamurai()) {
			System.out.println("  - " + s.getName());
		}
		
		System.out.println("Comerciantes:");
		for (Edo_Society m : xogunatoTokugawa.getMerchants()) {
			System.out.println("  - " + m.getName());
		}
		
		System.out.println("Artesãos:");
		for (Edo_Society a : xogunatoTokugawa.getArtisians()) {
			System.out.println("  - " + a.getName());
		}
		
		System.out.println("Camponeses:");
		for (Edo_Society p : xogunatoTokugawa.getPeasants()) {
			System.out.println("  - " + p.getName());
		}
		
		System.out.println("Política Social: " + xogunatoTokugawa.getSocialPolicy().getObjective());
		System.out.println("Período: " + xogunatoTokugawa.getSocialPolicy().getStartPeriod().get(Calendar.YEAR) + 
				" - " + xogunatoTokugawa.getSocialPolicy().getEndPeriod().get(Calendar.YEAR));

	}
}
