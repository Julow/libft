/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 23:33:02 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_hmap.h"
#include "../hmap_internal.h"
#include <stdlib.h>

t_sub const		g_test_keys[] = {
	SUBC("Lorem"), SUBC("arcu,"), SUBC("vulputate"), SUBC("cubilia"), SUBC("arcu"), SUBC("sapien"), SUBC("diam"), SUBC("laoreet"),
	SUBC("ipsum"), SUBC("et"), SUBC("mi,"), SUBC("Curae;"), SUBC("nulla,"), SUBC("maximus"), SUBC("nisl"), SUBC("nunc"),
	SUBC("dolor"), SUBC("consequat"), SUBC("nec"), SUBC("Proin"), SUBC("tristique"), SUBC("purus"), SUBC("pharetra"), SUBC("et"),
	SUBC("sit"), SUBC("urna"), SUBC("facilisis"), SUBC("rutrum"), SUBC("sit"), SUBC("ornare"), SUBC("enim,"), SUBC("dui"),
	SUBC("amet,"), SUBC("molestie"), SUBC("sem"), SUBC("erat"), SUBC("amet"), SUBC("efficitur."), SUBC("ac"), SUBC("dapibus,"),
	SUBC("consectetur"), SUBC("sed."), SUBC("sodales"), SUBC("eu"), SUBC("sodales"), SUBC("Nunc"), SUBC("auctor"), SUBC("ac"),
	SUBC("adipiscing"), SUBC("Aenean"), SUBC("vitae."), SUBC("elit"), SUBC("eu,"), SUBC("ut"), SUBC("mauris"), SUBC("semper"),
	SUBC("elit."), SUBC("feugiat"), SUBC("Suspendisse"), SUBC("elementum"), SUBC("commodo"), SUBC("venenatis"), SUBC("metus"), SUBC("lorem"),
	SUBC("In"), SUBC("sodales"), SUBC("vitae"), SUBC("interdum."), SUBC("et"), SUBC("magna."), SUBC("ut"), SUBC("ultrices."),
	SUBC("vitae"), SUBC("lacinia."), SUBC("vulputate"), SUBC("Aliquam"), SUBC("justo."), SUBC("Ut"), SUBC("elit."), SUBC("Mauris"),
	SUBC("metus"), SUBC("Integer"), SUBC("ligula,"), SUBC("non"), SUBC("Suspendisse"), SUBC("nisi"), SUBC("Morbi"), SUBC("tincidunt"),
	SUBC("ac"), SUBC("fermentum"), SUBC("et"), SUBC("ante"), SUBC("ac"), SUBC("enim,"), SUBC("cursus"), SUBC("mi"),
	SUBC("lacus"), SUBC("aliquet"), SUBC("euismod"), SUBC("ligula."), SUBC("diam"), SUBC("convallis"), SUBC("turpis"), SUBC("ipsum,"),
	SUBC("tristique"), SUBC("leo"), SUBC("purus."), SUBC("Phasellus"), SUBC("id"), SUBC("non"), SUBC("non"), SUBC("a"),
	SUBC("dictum"), SUBC("et"), SUBC("Etiam"), SUBC("at"), SUBC("ligula"), SUBC("dolor"), SUBC("metus"), SUBC("pretium"),
	SUBC("quis"), SUBC("porttitor."), SUBC("in"), SUBC("ligula"), SUBC("fringilla"), SUBC("vitae,"), SUBC("ornare"), SUBC("nisi"),
	SUBC("a"), SUBC("Ut"), SUBC("felis"), SUBC("malesuada,"), SUBC("efficitur."), SUBC("euismod"), SUBC("dignissim."), SUBC("euismod"),
	SUBC("eros."), SUBC("venenatis"), SUBC("tempor,"), SUBC("auctor"), SUBC("Integer"), SUBC("luctus"), SUBC("In"), SUBC("non."),
	SUBC("Nam"), SUBC("vulputate"), SUBC("egestas"), SUBC("turpis"), SUBC("tellus"), SUBC("elit."), SUBC("quis"), SUBC("Mauris"),
	SUBC("venenatis"), SUBC("libero"), SUBC("augue"), SUBC("vulputate,"), SUBC("nisi,"), SUBC("Sed"), SUBC("bibendum"), SUBC("sagittis"),
	SUBC("gravida"), SUBC("dapibus"), SUBC("ut,"), SUBC("interdum"), SUBC("dapibus"), SUBC("at"), SUBC("nisi,"), SUBC("gravida"),
	SUBC("mi,"), SUBC("congue."), SUBC("commodo"), SUBC("leo."), SUBC("vitae"), SUBC("augue"), SUBC("non"), SUBC("massa,"),
	SUBC("a"), SUBC("Maecenas"), SUBC("est."), SUBC("Nulla"), SUBC("tincidunt"), SUBC("enim."), SUBC("egestas"), SUBC("a"),
	SUBC("aliquam"), SUBC("at"), SUBC("Maecenas"), SUBC("convallis"), SUBC("non,"), SUBC("Maecenas"), SUBC("orci."), SUBC("commodo"),
	SUBC("est"), SUBC("ipsum"), SUBC("neque"), SUBC("odio"), SUBC("fermentum"), SUBC("ipsum"), SUBC("Interdum"), SUBC("magna"),
	SUBC("dapibus"), SUBC("ac"), SUBC("erat,"), SUBC("vitae"), SUBC("ac"), SUBC("quam,"), SUBC("et"), SUBC("rhoncus"),
	SUBC("malesuada"), SUBC("eu."), SUBC("purus"), SUBC("consequat"), SUBC("odio"), SUBC("tellus."), SUBC("laoreet"), SUBC("malesuada"), SUBC("id."),
	SUBC("fames"), SUBC("Phasellus"), SUBC("auctor"), SUBC("nec"), SUBC("imperdiet,"), SUBC("Quisque"), SUBC("vitae"), SUBC("fames"), SUBC("Nullam"),
	SUBC("ac"), SUBC("tempor"), SUBC("laoreet."), SUBC("tincidunt"), SUBC("quis"), SUBC("euismod"), SUBC("dui"), SUBC("ac"), SUBC("id"),
	SUBC("turpis"), SUBC("quam"), SUBC("Fusce"), SUBC("vitae,"), SUBC("tempor"), SUBC("varius"), SUBC("non,"), SUBC("ante"), SUBC("lorem"),
	SUBC("egestas."), SUBC("quis"), SUBC("egestas,"), SUBC("feugiat"), SUBC("nisi"), SUBC("diam"), SUBC("molestie"), SUBC("ipsum"), SUBC("eu"),
	SUBC("Curabitur"), SUBC("accumsan"), SUBC("felis"), SUBC("ut"), SUBC("sagittis."), SUBC("in"), SUBC("condimentum"), SUBC("primis"), SUBC("metus"),
	SUBC("euismod"), SUBC("suscipit."), SUBC("et"), SUBC("tellus."), SUBC("Aenean"), SUBC("iaculis."), SUBC("purus."), SUBC("in"), SUBC("egestas"),
	SUBC("quam"), SUBC("Sed"), SUBC("aliquam"), SUBC("Nullam"), SUBC("ac"), SUBC("Suspendisse"), SUBC("Aliquam"), SUBC("faucibus."), SUBC("ornare"),
	SUBC("ac"), SUBC("pretium"), SUBC("sodales,"), SUBC("eleifend"), SUBC("venenatis"), SUBC("suscipit,"), SUBC("cursus"), SUBC("Sed"), SUBC("non"),
	SUBC("porta"), SUBC("metus"), SUBC("leo"), SUBC("dui"), SUBC("metus."), SUBC("tortor"), SUBC("accumsan"), SUBC("finibus"), SUBC("eu"),
	SUBC("cursus."), SUBC("nisl,"), SUBC("est"), SUBC("sem,"), SUBC("Etiam"), SUBC("ac"), SUBC("semper."), SUBC("lectus"), SUBC("lacus.Mauris"),
	SUBC("Nullam"), SUBC("at"), SUBC("vestibulum"), SUBC("non"), SUBC("sodales"), SUBC("viverra"), SUBC("Sed"), SUBC("non"), SUBC("lacinia"),
	SUBC("commodo"), SUBC("tristique"), SUBC("ex,"), SUBC("bibendum"), SUBC("tincidunt"), SUBC("lacinia,"), SUBC("sit"), SUBC("ex"), SUBC("arcu"),
	SUBC("et"), SUBC("ipsum"), SUBC("ultricies"), SUBC("mauris"), SUBC("condimentum."), SUBC("ipsum"), SUBC("amet"), SUBC("aliquet"), SUBC("et"),
	SUBC("lectus"), SUBC("pulvinar"), SUBC("pretium"), SUBC("sollicitudin"), SUBC("Proin"), SUBC("justo"), SUBC("varius"), SUBC("posuere."), SUBC("leo"),
	SUBC("eget"), SUBC("et."), SUBC("nulla"), SUBC("sed."), SUBC("sit"), SUBC("aliquet"), SUBC("massa."), SUBC("Sed"), SUBC("commodo,"),
	SUBC("dignissim."), SUBC("Nunc"), SUBC("sapien"), SUBC("Vestibulum"), SUBC("amet"), SUBC("lorem,"), SUBC("Quisque"), SUBC("convallis"), SUBC("vel"),
	SUBC("Sed"), SUBC("vulputate"), SUBC("ac"), SUBC("id"), SUBC("faucibus"), SUBC("ac"), SUBC("scelerisque"), SUBC("orci"), SUBC("semper"),
	SUBC("ac"), SUBC("tristique"), SUBC("dui."), SUBC("quam"), SUBC("ligula,"), SUBC("elementum"), SUBC("lorem"), SUBC("nulla,"), SUBC("augue"),
	SUBC("pellentesque"), SUBC("lorem"), SUBC("Morbi"), SUBC("vel"), SUBC("nec"), SUBC("diam"), SUBC("ac"), SUBC("hendrerit"), SUBC("semper."),
	SUBC("magna.Maecenas"), SUBC("ac"), SUBC("augue"), SUBC("risus"), SUBC("lobortis"), SUBC("tortor"), SUBC("fermentum"), SUBC("hendrerit"), SUBC("In"),
	SUBC("lacinia"), SUBC("malesuada."), SUBC("magna,"), SUBC("tempus"), SUBC("metus."), SUBC("at"), SUBC("euismod.Duis"), SUBC("magna"), SUBC("tellus"),
	SUBC("cursus"), SUBC("Sed"), SUBC("posuere"), SUBC("blandit"), SUBC("Donec"), SUBC("erat."), SUBC("at"), SUBC("mollis"), SUBC("velit,"),
	SUBC("magna"), SUBC("ut"), SUBC("sit"), SUBC("sit"), SUBC("ultrices"), SUBC("Aliquam"), SUBC("feugiat"), SUBC("sit"), SUBC("gravida"),
	SUBC("consequat"), SUBC("sem"), SUBC("amet"), SUBC("amet"), SUBC("augue"), SUBC("sit"), SUBC("dui."), SUBC("amet."), SUBC("quis"),
	SUBC("efficitur."), SUBC("sagittis,"), SUBC("nulla"), SUBC("vel"), SUBC("a"), SUBC("amet"), SUBC("Suspendisse"), SUBC("Proin"), SUBC("vehicula"),
	SUBC("Curabitur"), SUBC("condimentum"), SUBC("eu,"), SUBC("tortor."), SUBC("justo"), SUBC("est"), SUBC("sit"), SUBC("egestas"), SUBC("nec,"),
	SUBC("fringilla"), SUBC("augue"), SUBC("placerat"), SUBC("Nulla"), SUBC("iaculis"), SUBC("convallis"), SUBC("amet"), SUBC("ultricies"), SUBC("sollicitudin"),
	SUBC("iaculis"), SUBC("sit"), SUBC("ullamcorper"), SUBC("sollicitudin"), SUBC("congue."), SUBC("arcu"), SUBC("tortor"), SUBC("arcu.Aenean"), SUBC("congue"),
	SUBC("ex."), SUBC("amet,"), SUBC("dolor."), SUBC("ex"), SUBC("Aliquam"), SUBC("pellentesque"), SUBC("quis"), SUBC("vel"), SUBC("justo."),
	SUBC("Praesent"), SUBC("condimentum"), SUBC("Vestibulum"), SUBC("quis"), SUBC("scelerisque"), SUBC("vulputate"), SUBC("diam"), SUBC("nulla"), SUBC("Sed"),
	SUBC("vehicula"), SUBC("sapien."), SUBC("nec"), SUBC("elit"), SUBC("ut"), SUBC("vitae"), SUBC("tincidunt"), SUBC("eleifend,"), SUBC("vitae"),
	SUBC("odio"), SUBC("Nam"), SUBC("vehicula"), SUBC("facilisis,"), SUBC("quam"), SUBC("sit"), SUBC("porttitor"), SUBC("venenatis"), SUBC("aliquet"),
	SUBC("non"), SUBC("tempus"), SUBC("erat."), SUBC("eget"), SUBC("et"), SUBC("amet"), SUBC("in"), SUBC("nisi"), SUBC("magna."),
	SUBC("est"), SUBC("facilisis"), SUBC("Sed"), SUBC("fermentum"), SUBC("vehicula."), SUBC("mi."), SUBC("at"), SUBC("a,"), SUBC("Vivamus"),
	SUBC("pulvinar,"), SUBC("pretium."), SUBC("laoreet"), SUBC("ante"), SUBC("Morbi"), SUBC("Donec"), SUBC("ligula."), SUBC("tincidunt"), SUBC("tortor"),
	SUBC("eget"), SUBC("Nullam"), SUBC("risus"), SUBC("gravida."), SUBC("consectetur"), SUBC("venenatis"), SUBC("Ut"), SUBC("arcu."), SUBC("ante,"),
	SUBC("pellentesque"), SUBC("lorem"), SUBC("et"), SUBC("Pellentesque"), SUBC("purus"), SUBC("urna"), SUBC("tincidunt"), SUBC("Vivamus"), SUBC("finibus"),
	SUBC("metus"), SUBC("neque,"), SUBC("lacus"), SUBC("nec"), SUBC("a"), SUBC("sed"), SUBC("convallis"), SUBC("non"), SUBC("non"),
	SUBC("ultricies."), SUBC("faucibus"), SUBC("placerat,"), SUBC("bibendum"), SUBC("libero"), SUBC("tortor"), SUBC("eros."), SUBC("elit"), SUBC("blandit"),
	SUBC("Cras"), SUBC("fringilla"), SUBC("eget"), SUBC("leo."), SUBC("tempus,"), SUBC("pretium"), SUBC("Quisque"), SUBC("at"), SUBC("vitae,"),
	SUBC("quam"), SUBC("ullamcorper"), SUBC("ultricies"), SUBC("Duis"), SUBC("id"), SUBC("luctus."), SUBC("aliquam"), SUBC("arcu"), SUBC("tempor"),
	SUBC("purus,"), SUBC("eget,"), SUBC("nulla"), SUBC("faucibus"), SUBC("blandit"), SUBC("Nulla"), SUBC("commodo"), SUBC("condimentum"), SUBC("ac"),
	SUBC("ullamcorper"), SUBC("vehicula"), SUBC("porttitor.Nullam"), SUBC("orci"), SUBC("ipsum"), SUBC("sapien"), SUBC("diam"), SUBC("efficitur"), SUBC("magna."),
	SUBC("vel"), SUBC("a"), SUBC("dictum"), SUBC("ut"), SUBC("luctus."), SUBC("nisl,"), SUBC("eget"), SUBC("eget"), SUBC("Integer"),
	SUBC("commodo"), SUBC("mauris."), SUBC("ultrices"), SUBC("nisi"), SUBC("Suspendisse"), SUBC("pharetra"), SUBC("congue."), SUBC("et"), SUBC("mattis"),
	SUBC("posuere,"), SUBC("Integer"), SUBC("quam"), SUBC("convallis"), SUBC("vulputate"), SUBC("tempus"), SUBC("Lorem"), SUBC("eros."), SUBC("accumsan"),
	SUBC("euismod"), SUBC("vestibulum"), SUBC("vel"), SUBC("sagittis."), SUBC("eleifend"), SUBC("dui"), SUBC("ipsum"), SUBC("Mauris"), SUBC("sem"),
	SUBC("vel"), SUBC("placerat"), SUBC("tempor."), SUBC("Mauris"), SUBC("felis,"), SUBC("non,"), SUBC("dolor"), SUBC("et"), SUBC("et"),
	SUBC("purus."), SUBC("mi,"), SUBC("Quisque"), SUBC("sed"), SUBC("at"), SUBC("facilisis"), SUBC("sit"), SUBC("posuere"), SUBC("maximus."),
	SUBC("Aliquam"), SUBC("et"), SUBC("scelerisque"), SUBC("lacus"), SUBC("pretium"), SUBC("pharetra"), SUBC("amet,"), SUBC("velit,"), SUBC("Nullam"),
	SUBC("vel"), SUBC("pharetra"), SUBC("fringilla"), SUBC("in"), SUBC("sapien"), SUBC("ante."), SUBC("consectetur"), SUBC("in"), SUBC("ut"),
	SUBC("convallis"), SUBC("felis"), SUBC("tellus,"), SUBC("lectus"), SUBC("lacinia"), SUBC("Curabitur"), SUBC("adipiscing"), SUBC("accumsan"), SUBC("quam"),
	SUBC("sem."), SUBC("ultrices"), SUBC("lacinia"), SUBC("elementum"), SUBC("id.Sed"), SUBC("in"), SUBC("elit."), SUBC("neque."), SUBC("vestibulum,"),
	SUBC("Sed"), SUBC("et.In"), SUBC("fringilla"), SUBC("luctus"), SUBC("sagittis"), SUBC("rutrum"), SUBC("Donec"), SUBC("Curabitur"), SUBC("placerat"),
	SUBC("auctor"), SUBC("auctor"), SUBC("elit"), SUBC("sed"), SUBC("elementum"), SUBC("libero,"), SUBC("non"), SUBC("ultrices"), SUBC("erat"),
	SUBC("pellentesque"), SUBC("felis"), SUBC("mattis"), SUBC("ut"), SUBC("malesuada."), SUBC("tempus"), SUBC("lectus"), SUBC("placerat"), SUBC("ac,"),
	SUBC("posuere."), SUBC("ac"), SUBC("vitae."), SUBC("mi.Etiam"), SUBC("Nam"), SUBC("rhoncus"), SUBC("nunc."), SUBC("vestibulum."), SUBC("rutrum"),
	SUBC("Aenean"), SUBC("nisi"), SUBC("Nunc"), SUBC("aliquet"), SUBC("condimentum,"), SUBC("ex."), SUBC("Proin"), SUBC("Curabitur"), SUBC("ipsum."),
	SUBC("non"), SUBC("finibus,"), SUBC("felis"), SUBC("euismod"), SUBC("augue"), SUBC("Etiam"), SUBC("nec"), SUBC("libero"), SUBC("Mauris"),
	SUBC("ornare"), SUBC("nec"), SUBC("urna,"), SUBC("lorem"), SUBC("in"), SUBC("ultricies"), SUBC("eros"), SUBC("turpis,"), SUBC("blandit"),
	SUBC("nunc,"), SUBC("placerat"), SUBC("sagittis"), SUBC("vel"), SUBC("pulvinar"), SUBC("consectetur"), SUBC("at"), SUBC("pretium"), SUBC("mi"),
	SUBC("vel"), SUBC("augue"), SUBC("sed"), SUBC("hendrerit."), SUBC("molestie,"), SUBC("eros,"), SUBC("ex"), SUBC("sit"), SUBC("vel"),
	SUBC("cursus"), SUBC("iaculis."), SUBC("tortor"), SUBC("Vestibulum"), SUBC("sem"), SUBC("sit"), SUBC("volutpat"), SUBC("amet"), SUBC("lacus"),
	SUBC("nisl."), SUBC("Cras"), SUBC("at,"), SUBC("ante"), SUBC("dui"), SUBC("amet"), SUBC("accumsan"), SUBC("sem"), SUBC("dictum"),
	SUBC("Maecenas"), SUBC("vitae"), SUBC("faucibus"), SUBC("ipsum"), SUBC("volutpat"), SUBC("aliquet"), SUBC("et"), SUBC("in,"), SUBC("placerat."),
	SUBC("volutpat"), SUBC("nunc"), SUBC("auctor"), SUBC("primis"), SUBC("eros,"), SUBC("ligula"), SUBC("quis"), SUBC("vehicula"), SUBC("Pellentesque"),
	SUBC("ultrices"), SUBC("porta"), SUBC("turpis."), SUBC("in"), SUBC("et"), SUBC("scelerisque"), SUBC("ipsum."), SUBC("ullamcorper"), SUBC("habitant"),
	SUBC("ipsum,"), SUBC("nisi"), SUBC("In"), SUBC("faucibus"), SUBC("sollicitudin"), SUBC("in."), SUBC("Etiam"), SUBC("lorem."), SUBC("morbi"),
	SUBC("fermentum"), SUBC("lobortis"), SUBC("luctus"), SUBC("orci"), SUBC("lorem"), SUBC("Aliquam"), SUBC("placerat,"), SUBC("Fusce"), SUBC("tristique"),
	SUBC("malesuada"), SUBC("posuere."), SUBC("aliquet"), SUBC("luctus"), SUBC("sem"), SUBC("vel"), SUBC("nulla"), SUBC("fringilla"), SUBC("senectus"),
	SUBC("urna"), SUBC("Duis"), SUBC("accumsan."), SUBC("et"), SUBC("maximus"), SUBC("varius"), SUBC("ac"), SUBC("pretium"), SUBC("et"),
	SUBC("lobortis"), SUBC("auctor"), SUBC("Proin"), SUBC("ultrices"), SUBC("augue."), SUBC("tellus.Ut"), SUBC("mattis"), SUBC("porttitor."), SUBC("netus"),
	SUBC("vel."), SUBC("accumsan"), SUBC("varius"), SUBC("posuere"), SUBC("Morbi"), SUBC("et"), SUBC("facilisis,"), SUBC("Donec"), SUBC("et"),
	SUBC("curvy"), SUBC("sink"), SUBC("bit"), SUBC("sisters"), SUBC("excellent"), SUBC("dare"), SUBC("wood"), SUBC("aboard"), SUBC("screeching"), SUBC("pen"), SUBC("copper"), SUBC("venomous"), SUBC("pull"), SUBC("touch"), SUBC("exercise"), SUBC("manage"), SUBC("open"), SUBC("versed"), SUBC("abundant"), SUBC("confused"), SUBC("eyes"), SUBC("tendency"), SUBC("hope"), SUBC("few"), SUBC("record"), SUBC("whip"), SUBC("juice"), SUBC("likeable"), SUBC("rebel"), SUBC("gruesome"),
	SUBC("flashy"), SUBC("bitter"), SUBC("babies"), SUBC("trip"), SUBC("rings"), SUBC("tranquil"), SUBC("damage"), SUBC("brainy"), SUBC("mom"), SUBC("suppose"), SUBC("stitch"), SUBC("fretful"), SUBC("violet"), SUBC("uninterested"), SUBC("advice"), SUBC("bath"), SUBC("luxuriant"), SUBC("ablaze"), SUBC("dinosaurs"), SUBC("handsomely"), SUBC("dirt"), SUBC("poor"), SUBC("wobble"), SUBC("question"), SUBC("waggish"), SUBC("smash"), SUBC("crack"), SUBC("trees"), SUBC("adhesive"), SUBC("gaudy"),
	SUBC("curve"), SUBC("stereotyped"), SUBC("pancake"), SUBC("practise"), SUBC("guide"), SUBC("enchanted"), SUBC("middle"), SUBC("crowded"), SUBC("ski"), SUBC("walk"), SUBC("duck"), SUBC("berry"), SUBC("inform"), SUBC("like"), SUBC("nice"), SUBC("complain"), SUBC("tax"), SUBC("matter"), SUBC("trust"), SUBC("fairies"), SUBC("fish"), SUBC("sand"), SUBC("exchange"), SUBC("lonely"), SUBC("coal"), SUBC("open"), SUBC("protective"), SUBC("sheep"), SUBC("fierce"), SUBC("nosy"),
	SUBC("poke"), SUBC("rescue"), SUBC("humdrum"), SUBC("upset"), SUBC("increase"), SUBC("functional"), SUBC("air"), SUBC("kneel"), SUBC("record"), SUBC("remember"), SUBC("discreet"), SUBC("sleet"), SUBC("supply"), SUBC("friends"), SUBC("stew"), SUBC("home"), SUBC("lake"), SUBC("lick"), SUBC("hurt"), SUBC("ugly"), SUBC("calculate"), SUBC("inject"), SUBC("dress"), SUBC("work"), SUBC("puzzling"), SUBC("nail"), SUBC("match"), SUBC("plot"), SUBC("fair"), SUBC("doubtful"),
	SUBC("interest"), SUBC("needy"), SUBC("memory"), SUBC("tired"), SUBC("tease"), SUBC("paste"), SUBC("dapper"), SUBC("innocent"), SUBC("bizarre"), SUBC("actually"), SUBC("unique"), SUBC("glue"), SUBC("important"), SUBC("baseball"), SUBC("mammoth"), SUBC("tumble"), SUBC("psychedelic"), SUBC("clam"), SUBC("handsome"), SUBC("ship"), SUBC("station"), SUBC("graceful"), SUBC("nest"), SUBC("forgetful"), SUBC("blood"), SUBC("relax"), SUBC("peace"), SUBC("toothsome"), SUBC("uppity"), SUBC("soda"),
	SUBC("expect"), SUBC("green"), SUBC("x-ray"), SUBC("slave"), SUBC("rigid"), SUBC("furry"), SUBC("spotty"), SUBC("dust"), SUBC("unsuitable"), SUBC("person"), SUBC("kill"), SUBC("improve"), SUBC("place"), SUBC("thinkable"), SUBC("rely"), SUBC("team"), SUBC("juicy"), SUBC("half"), SUBC("uneven"), SUBC("quiver"), SUBC("unruly"), SUBC("grouchy"), SUBC("ducks"), SUBC("worthless"), SUBC("available"), SUBC("fold"), SUBC("verdant"), SUBC("agonizing"), SUBC("embarrassed"), SUBC("spotted"),
	SUBC("quixotic"), SUBC("agree"), SUBC("rest"), SUBC("arithmetic"), SUBC("dry"), SUBC("arm"), SUBC("birthday"), SUBC("memorise"), SUBC("level"), SUBC("womanly"), SUBC("stingy"), SUBC("feigned"), SUBC("argue"), SUBC("trail"), SUBC("sparkling"), SUBC("guarded"), SUBC("marked"), SUBC("pollution"), SUBC("well-to-do"), SUBC("smiling"), SUBC("gifted"), SUBC("whip"), SUBC("creature"), SUBC("sign"), SUBC("notice"), SUBC("sign"), SUBC("rustic"), SUBC("van"), SUBC("big"), SUBC("reward"),
	SUBC("quizzical"), SUBC("smoggy"), SUBC("iron"), SUBC("punishment"), SUBC("piquant"), SUBC("unpack"), SUBC("structure"), SUBC("compare"), SUBC("driving"), SUBC("wild"), SUBC("cow"), SUBC("new"), SUBC("occur"), SUBC("therapeutic"), SUBC("horse"), SUBC("supreme"), SUBC("wandering"), SUBC("throne"), SUBC("teaching"), SUBC("curly"), SUBC("bathe"), SUBC("previous"), SUBC("cultured"), SUBC("tremendous"), SUBC("private"), SUBC("redundant"), SUBC("vest"), SUBC("alluring"), SUBC("acoustic"), SUBC("peck"),
	SUBC("twig"), SUBC("fanatical"), SUBC("decision"), SUBC("huge"), SUBC("shut"), SUBC("suck"), SUBC("chess"), SUBC("pets"), SUBC("beneficial"), SUBC("trade"), SUBC("stiff"), SUBC("curtain"), SUBC("country"), SUBC("linen"), SUBC("able"), SUBC("spiritual"), SUBC("measure"), SUBC("frail"), SUBC("instinctive"), SUBC("fear"), SUBC("mug"), SUBC("lumpy"), SUBC("women"), SUBC("part"), SUBC("haircut"), SUBC("surprise"), SUBC("morning"), SUBC("trite"), SUBC("join"), SUBC("rub"),
	SUBC("unequaled"), SUBC("lip"), SUBC("confuse"), SUBC("cynical"), SUBC("hug"), SUBC("flood"), SUBC("shock"), SUBC("future"), SUBC("plain"), SUBC("suit"), SUBC("panicky"), SUBC("relieved"), SUBC("quill"), SUBC("wakeful"), SUBC("appreciate"), SUBC("murky"), SUBC("third"), SUBC("waste"), SUBC("branch"), SUBC("condemned"), SUBC("decay"), SUBC("excited"), SUBC("shrug"), SUBC("bushes"), SUBC("fly"), SUBC("test"), SUBC("righteous"), SUBC("wary"), SUBC("top"), SUBC("dreary"),
	SUBC("reading"), SUBC("scientific"), SUBC("clover"), SUBC("title"), SUBC("grubby"), SUBC("dress"), SUBC("bewildered"), SUBC("quince"), SUBC("thirsty"), SUBC("size"), SUBC("books"), SUBC("terrible"), SUBC("giddy"), SUBC("simplistic"), SUBC("keen"), SUBC("tip"), SUBC("naughty"), SUBC("overrated"), SUBC("decisive"), SUBC("help"), SUBC("cry"), SUBC("kindly"), SUBC("glossy"), SUBC("head"), SUBC("shelf"), SUBC("sneaky"), SUBC("aquatic"), SUBC("telephone"), SUBC("tough"), SUBC("milky"),
	SUBC("eggnog"), SUBC("representative"), SUBC("daughter"), SUBC("hushed"), SUBC("connection"), SUBC("invincible"), SUBC("delay"), SUBC("lively"), SUBC("deep"), SUBC("parsimonious"), SUBC("common"), SUBC("grease"), SUBC("fear"), SUBC("nut"), SUBC("plan"), SUBC("cart"), SUBC("thoughtless"), SUBC("edge"), SUBC("grass"), SUBC("rhythm"), SUBC("fat"), SUBC("incandescent"), SUBC("destroy"), SUBC("hydrant"), SUBC("different"), SUBC("trick"), SUBC("plants"), SUBC("houses"), SUBC("secretary"), SUBC("delicious"),
	SUBC("suggest"), SUBC("faint"), SUBC("behavior"), SUBC("chicken"), SUBC("chief"), SUBC("kiss"), SUBC("smart"), SUBC("care"), SUBC("whirl"), SUBC("current"), SUBC("income"), SUBC("nervous"), SUBC("drip"), SUBC("wash"), SUBC("car"), SUBC("sky"), SUBC("place"), SUBC("obtain"), SUBC("burly"), SUBC("water"), SUBC("men"), SUBC("bounce"), SUBC("learn"), SUBC("crime"), SUBC("wine"), SUBC("frame"), SUBC("toys"), SUBC("adventurous"), SUBC("high-pitched"), SUBC("stranger"),
	SUBC("absorbed"), SUBC("lunchroom"), SUBC("whine"), SUBC("optimal"), SUBC("peel"), SUBC("day"), SUBC("bell"), SUBC("train"), SUBC("acid"), SUBC("hospital"), SUBC("unbiased"), SUBC("name"), SUBC("juvenile"), SUBC("button"), SUBC("good"), SUBC("hose"), SUBC("mine"), SUBC("challenge"), SUBC("military"), SUBC("impartial"), SUBC("cough"), SUBC("efficient"), SUBC("wet"), SUBC("petite"), SUBC("book"), SUBC("reproduce"), SUBC("smile"), SUBC("crack"), SUBC("untidy"), SUBC("joke"),
	SUBC("skirt"), SUBC("imperfect"), SUBC("terrific"), SUBC("pig"), SUBC("plastic"), SUBC("ill-informed"), SUBC("coil"), SUBC("lazy"), SUBC("sad"), SUBC("offend"), SUBC("quack"), SUBC("reflective"), SUBC("malicious"), SUBC("juggle"), SUBC("bury"), SUBC("tempt"), SUBC("testy"), SUBC("numberless"), SUBC("thoughtful"), SUBC("threatening"), SUBC("bulb"), SUBC("cause"), SUBC("chase"), SUBC("careless"), SUBC("muscle"), SUBC("meal"), SUBC("trot"), SUBC("nebulous"), SUBC("staking"), SUBC("awful"),
	SUBC("clear"), SUBC("laborer"), SUBC("route"), SUBC("knee"), SUBC("spoon"), SUBC("note"), SUBC("admire"), SUBC("advise"), SUBC("finicky"), SUBC("cows"), SUBC("nostalgic"), SUBC("null"), SUBC("super"), SUBC("film"), SUBC("yawn"), SUBC("snobbish"), SUBC("daily"), SUBC("muddled"), SUBC("moaning"), SUBC("black"), SUBC("coordinated"), SUBC("grateful"), SUBC("yarn"), SUBC("boy"), SUBC("embarrass"), SUBC("tan"), SUBC("joyous"), SUBC("phone"), SUBC("laughable"), SUBC("woebegone"),
	SUBC("ad"), SUBC("hoc"), SUBC("retire"), SUBC("pathetic"), SUBC("nine"), SUBC("flag"), SUBC("dust"), SUBC("untidy"), SUBC("right"), SUBC("eye"), SUBC("gather"), SUBC("bubble"), SUBC("noise"), SUBC("obese"), SUBC("lean"), SUBC("wipe"), SUBC("pest"), SUBC("cure"), SUBC("argument"), SUBC("bedroom"), SUBC("whistle"), SUBC("plant"), SUBC("substance"), SUBC("point"), SUBC("clammy"), SUBC("pizzas"), SUBC("brake"), SUBC("zonked"), SUBC("object"), SUBC("kaput"),
	SUBC("classy"), SUBC("barbarous"), SUBC("spurious"), SUBC("enormous"), SUBC("stormy"), SUBC("imported"), SUBC("polish"), SUBC("friendly"), SUBC("rhyme"), SUBC("brother"), SUBC("filthy"), SUBC("aberrant"), SUBC("regular"), SUBC("passenger"), SUBC("didactic"), SUBC("pink"), SUBC("breathe"), SUBC("frighten"), SUBC("shoes"), SUBC("neck"), SUBC("pricey"), SUBC("cluttered"), SUBC("flavor"), SUBC("company"), SUBC("equable"), SUBC("cooperative"), SUBC("separate"), SUBC("resonant"), SUBC("floor"), SUBC("extra-large"),
	SUBC("scratch"), SUBC("hook"), SUBC("male"), SUBC("volatile"), SUBC("dysfunctional"), SUBC("soggy"), SUBC("grey"), SUBC("heavenly"), SUBC("elated"), SUBC("thick"), SUBC("quaint"), SUBC("playground"), SUBC("ambiguous"), SUBC("slow"), SUBC("curl"), SUBC("coach"), SUBC("shiver"), SUBC("prickly"), SUBC("spotless"), SUBC("hand"), SUBC("crate"), SUBC("bouncy"), SUBC("reflect"), SUBC("entertain"), SUBC("foamy"), SUBC("feeble"), SUBC("highfalutin"), SUBC("thank"), SUBC("ready"), SUBC("hat"),
	SUBC("veil"), SUBC("sweater"), SUBC("abrupt"), SUBC("amuse"), SUBC("boorish"), SUBC("ajar"), SUBC("building"), SUBC("numerous"), SUBC("distance"), SUBC("please"), SUBC("cushion"), SUBC("pretty"), SUBC("minute"), SUBC("divide"), SUBC("farm"), SUBC("brash"), SUBC("bored"), SUBC("beds"), SUBC("apparatus"), SUBC("realise"), SUBC("view"), SUBC("suit"), SUBC("crazy"), SUBC("reply"), SUBC("disappear"), SUBC("skinny"), SUBC("sloppy"), SUBC("order"), SUBC("shocking"), SUBC("ritzy"),
	SUBC("torpid"), SUBC("geese"), SUBC("brass"), SUBC("scold"), SUBC("coat"), SUBC("remind"), SUBC("wind"), SUBC("angle"), SUBC("cannon"), SUBC("horn"), SUBC("evanescent"), SUBC("front"), SUBC("parallel"), SUBC("servant"), SUBC("zebra"), SUBC("dark"), SUBC("tasteless"), SUBC("harass"), SUBC("knowledge"), SUBC("acoustics"), SUBC("impulse"), SUBC("dirty"), SUBC("bump"), SUBC("disgusting"), SUBC("cloistered"), SUBC("incompetent"), SUBC("point"), SUBC("lying"), SUBC("jittery"), SUBC("superb"),
	SUBC("oranges"), SUBC("living"), SUBC("appear"), SUBC("play"), SUBC("onerous"), SUBC("elderly"), SUBC("fang"), SUBC("hum"), SUBC("enjoy"), SUBC("identify"), SUBC("slope"), SUBC("underwear"), SUBC("jar"), SUBC("wish"), SUBC("truthful"), SUBC("boundless"), SUBC("year"), SUBC("futuristic"), SUBC("unbecoming"), SUBC("walk"), SUBC("bite"), SUBC("vacation"), SUBC("boat"), SUBC("cheap"), SUBC("bake"), SUBC("flawless"), SUBC("present"), SUBC("obtainable"), SUBC("spill"), SUBC("sister"),
	SUBC("accurate"), SUBC("abashed"), SUBC("taboo"), SUBC("fork"), SUBC("rush"), SUBC("robin"), SUBC("rightful"), SUBC("curve"), SUBC("happen"), SUBC("boiling"), SUBC("tender"), SUBC("known"), SUBC("outgoing"), SUBC("pushy"), SUBC("cover"), SUBC("guide"), SUBC("imminent"), SUBC("sable"), SUBC("grip"), SUBC("ghost"), SUBC("illegal"), SUBC("pointless"), SUBC("pray"), SUBC("complete"), SUBC("icicle"), SUBC("puzzled"), SUBC("smooth"), SUBC("instrument"), SUBC("naive"), SUBC("dance"),
	SUBC("pear"), SUBC("flowery"), SUBC("oven"), SUBC("earsplitting"), SUBC("dream"), SUBC("town"), SUBC("honey"), SUBC("wash"), SUBC("sedate"), SUBC("creator"), SUBC("obey"), SUBC("scare"), SUBC("dolls"), SUBC("blot"), SUBC("industrious"), SUBC("attack"), SUBC("hand"), SUBC("head"), SUBC("comparison"), SUBC("hard"), SUBC("carry"), SUBC("low"), SUBC("stare"), SUBC("dear"), SUBC("fearless"), SUBC("weather"), SUBC("shrill"), SUBC("merciful"), SUBC("many"), SUBC("rambunctious"),
	SUBC("health"), SUBC("fill"), SUBC("range"), SUBC("chin"), SUBC("discussion"), SUBC("animal"), SUBC("furtive"), SUBC("deranged"), SUBC("ossified"), SUBC("hope"), SUBC("kick"), SUBC("stove"), SUBC("chalk"), SUBC("draconian"), SUBC("madly"), SUBC("name"), SUBC("cup"), SUBC("owe"), SUBC("store"), SUBC("vacuous"), SUBC("elite"), SUBC("squeak"), SUBC("brush"), SUBC("zealous"), SUBC("level"), SUBC("same"), SUBC("lewd"), SUBC("fancy"), SUBC("true"), SUBC("pumped"),
	SUBC("acrid"), SUBC("precede"), SUBC("languid"), SUBC("airplane"), SUBC("push"), SUBC("watery"), SUBC("tall"), SUBC("cooing"), SUBC("flap"), SUBC("soap"), SUBC("stamp"), SUBC("overconfident"), SUBC("special"), SUBC("frightened"), SUBC("bear"), SUBC("deceive"), SUBC("knife"), SUBC("visit"), SUBC("capricious"), SUBC("rat"), SUBC("zany"), SUBC("prefer"), SUBC("moon"), SUBC("rifle"), SUBC("spark"), SUBC("mess"), SUBC("up"), SUBC("plastic"), SUBC("childlike"), SUBC("rude"),
	SUBC("crash"), SUBC("sick"), SUBC("dime"), SUBC("ultra"), SUBC("cause"), SUBC("slim"), SUBC("aggressive"), SUBC("hate"), SUBC("abounding"), SUBC("funny"), SUBC("scissors"), SUBC("string"), SUBC("nimble"), SUBC("depressed"), SUBC("combative"), SUBC("fold"), SUBC("historical"), SUBC("peep"), SUBC("slip"), SUBC("bent"), SUBC("teeny-tiny"), SUBC("late"), SUBC("snatch"), SUBC("parched"), SUBC("squalid"), SUBC("plate"), SUBC("notebook"), SUBC("level"), SUBC("vivacious"), SUBC("kindhearted"),
	SUBC("crown"), SUBC("check"), SUBC("plausible"), SUBC("rake"), SUBC("intelligent"), SUBC("stream"), SUBC("library"), SUBC("zinc"), SUBC("hollow"), SUBC("zesty"), SUBC("adjustment"), SUBC("zippy"), SUBC("second"), SUBC("left"), SUBC("tangible"), SUBC("admit"), SUBC("somber"), SUBC("exclusive"), SUBC("share"), SUBC("face"), SUBC("waves"), SUBC("vanish"), SUBC("strange"), SUBC("grade"), SUBC("existence"), SUBC("flock"), SUBC("charge"), SUBC("squirrel"), SUBC("pleasant"), SUBC("material"),
	SUBC("exist"), SUBC("creepy"), SUBC("helpful"), SUBC("slip"), SUBC("grotesque"), SUBC("moor"), SUBC("ratty"), SUBC("diligent"), SUBC("dock"), SUBC("envious"), SUBC("decide"), SUBC("longing"), SUBC("tacky"), SUBC("time"), SUBC("gaze"), SUBC("type"), SUBC("event"), SUBC("nondescript"), SUBC("ground"), SUBC("wren"), SUBC("decorous"), SUBC("cloudy"), SUBC("blue-eyed"), SUBC("gigantic"), SUBC("serious"), SUBC("loaf"), SUBC("window"), SUBC("prevent"), SUBC("hall"), SUBC("free"),
	SUBC("yummy"), SUBC("drain"), SUBC("certain"), SUBC("steel"), SUBC("disarm"), SUBC("daffy"), SUBC("average"), SUBC("mature"), SUBC("spy"), SUBC("furniture"), SUBC("habitual"), SUBC("time"), SUBC("nose"), SUBC("steady"), SUBC("gamy"), SUBC("suspect"), SUBC("fowl"), SUBC("excite"), SUBC("ice"), SUBC("better"), SUBC("meat"), SUBC("utter"), SUBC("ten"), SUBC("bleach"), SUBC("well-made"), SUBC("hate"), SUBC("food"), SUBC("earn"), SUBC("relation"), SUBC("drown"),
	SUBC("stir"), SUBC("harbor"), SUBC("alike"), SUBC("wooden"), SUBC("adjoining"), SUBC("scared"), SUBC("sprout"), SUBC("camera"), SUBC("end"), SUBC("stain"), SUBC("grate"), SUBC("endurable"), SUBC("penitent"), SUBC("shame"), SUBC("pull"), SUBC("peaceful"), SUBC("expert"), SUBC("milk"), SUBC("stimulating"), SUBC("flesh"), SUBC("arrange"), SUBC("frame"), SUBC("loutish"), SUBC("waste"), SUBC("nasty"), SUBC("yellow"), SUBC("mend"), SUBC("snotty"), SUBC("use"), SUBC("drab"),
	SUBC("early"), SUBC("shelter"), SUBC("secretive"), SUBC("hour"), SUBC("develop"), SUBC("complete"), SUBC("abnormal"), SUBC("pocket"), SUBC("stuff"), SUBC("belligerent"), SUBC("recess"), SUBC("striped"), SUBC("sore"), SUBC("lame"), SUBC("sack"), SUBC("mute"), SUBC("fascinated"), SUBC("troubled"), SUBC("fancy"), SUBC("bright"), SUBC("abrasive"), SUBC("humorous"), SUBC("ahead"), SUBC("smile"), SUBC("disturbed"), SUBC("loving"), SUBC("useful"), SUBC("baby"), SUBC("power"), SUBC("full"),
	SUBC("wire"), SUBC("rot"), SUBC("one"), SUBC("irritating"), SUBC("reign"), SUBC("aboriginal"), SUBC("own"), SUBC("tank"), SUBC("gorgeous"), SUBC("sense"), SUBC("scrub"), SUBC("political"), SUBC("grin"), SUBC("wrench"), SUBC("uttermost"), SUBC("neat"), SUBC("slap"), SUBC("hungry"), SUBC("fruit"), SUBC("ear"), SUBC("silky"), SUBC("powder"), SUBC("interesting"), SUBC("return"), SUBC("jumpy"), SUBC("selective"), SUBC("road"), SUBC("seal"), SUBC("self"), SUBC("opposite"),
	SUBC("fasten"), SUBC("stamp"), SUBC("homely"), SUBC("visitor"), SUBC("mouth"), SUBC("changeable"), SUBC("property"), SUBC("songs"), SUBC("alive"), SUBC("committee"), SUBC("chilly"), SUBC("best"), SUBC("mice"), SUBC("noiseless"), SUBC("slow"), SUBC("annoy"), SUBC("load"), SUBC("pause"), SUBC("silly"), SUBC("magnificent"), SUBC("planes"), SUBC("yell"), SUBC("jeans"), SUBC("butter"), SUBC("shock"), SUBC("delirious"), SUBC("assorted"), SUBC("step"), SUBC("scarce"), SUBC("sturdy"),
	SUBC("oafish"), SUBC("decorate"), SUBC("idea"), SUBC("whistle"), SUBC("store"), SUBC("trouble"), SUBC("magenta"), SUBC("fabulous"), SUBC("radiate"), SUBC("exciting"), SUBC("majestic"), SUBC("cuddly"), SUBC("snail"), SUBC("bumpy"), SUBC("locket"), SUBC("tearful"), SUBC("surprise"), SUBC("spiders"), SUBC("recognise"), SUBC("bomb"), SUBC("tickle"), SUBC("value"), SUBC("unhealthy"), SUBC("skate"), SUBC("succeed"), SUBC("stupendous"), SUBC("judge"), SUBC("rule"), SUBC("mark"), SUBC("cool"),
	SUBC("regret"), SUBC("river"), SUBC("son"), SUBC("elegant"), SUBC("dizzy"), SUBC("truck"), SUBC("sour"), SUBC("holiday"), SUBC("mundane"), SUBC("irate"), SUBC("disagree"), SUBC("hurry"), SUBC("giant"), SUBC("sail"), SUBC("hobbies"), SUBC("comfortable"), SUBC("cough"), SUBC("outrageous"), SUBC("selfish"), SUBC("maddening"), SUBC("cherry"), SUBC("energetic"), SUBC("talented"), SUBC("communicate"), SUBC("program"), SUBC("sleepy"), SUBC("park"), SUBC("call"), SUBC("violent"), SUBC("suffer"),
	SUBC("broken"), SUBC("shade"), SUBC("caption"), SUBC("satisfying"), SUBC("night"), SUBC("bag"), SUBC("trace"), SUBC("infamous"), SUBC("drawer"), SUBC("birth"), SUBC("society"), SUBC("water"), SUBC("wise"), SUBC("noxious"), SUBC("unaccountable"), SUBC("warm"), SUBC("spiffy"), SUBC("quick"), SUBC("kiss"), SUBC("bait"), SUBC("shake"), SUBC("thrill"), SUBC("fortunate"), SUBC("disgusted"), SUBC("sun"), SUBC("exuberant"), SUBC("camp"), SUBC("solid"), SUBC("careful"), SUBC("sparkle"),
	SUBC("protest"), SUBC("burst"), SUBC("automatic"), SUBC("bang"), SUBC("hellish"), SUBC("glib"), SUBC("marvelous"), SUBC("debt"), SUBC("bone"), SUBC("school"), SUBC("stage"), SUBC("melted"), SUBC("ubiquitous"), SUBC("poised"), SUBC("island"), SUBC("guiltless"), SUBC("hover"), SUBC("repair"), SUBC("desert"), SUBC("swing"), SUBC("bridge"), SUBC("nest"), SUBC("invite"), SUBC("tree"), SUBC("white"), SUBC("voiceless"), SUBC("wave"), SUBC("eager"), SUBC("pin"), SUBC("makeshift"),
	SUBC("last"), SUBC("stop"), SUBC("picture"), SUBC("ancient"), SUBC("slimy"), SUBC("introduce"), SUBC("produce"), SUBC("frequent"), SUBC("drink"), SUBC("insidious"), SUBC("amusing"), SUBC("permissible"), SUBC("design"), SUBC("itchy"), SUBC("wink"), SUBC("toad"), SUBC("cobweb"), SUBC("delightful"), SUBC("flat"), SUBC("arrest"), SUBC("cold"), SUBC("possessive"), SUBC("milk"), SUBC("sort"), SUBC("standing"), SUBC("list"), SUBC("pedal"), SUBC("kettle"), SUBC("hissing"), SUBC("lumber"),
	SUBC("race"), SUBC("lush"), SUBC("warn"), SUBC("cute"), SUBC("expansion"), SUBC("economic"), SUBC("attract"), SUBC("disastrous"), SUBC("risk"), SUBC("knowledgeable"), SUBC("lighten"), SUBC("condition"), SUBC("pale"), SUBC("short"), SUBC("tricky"), SUBC("interrupt"), SUBC("force"), SUBC("mitten"), SUBC("want"), SUBC("colour"), SUBC("undesirable"), SUBC("join"), SUBC("substantial"), SUBC("cruel"), SUBC("close"), SUBC("achiever"), SUBC("false"), SUBC("clear"), SUBC("gratis"), SUBC("girls"),
	SUBC("question"), SUBC("wealth"), SUBC("sugar"), SUBC("lock"), SUBC("flippant"), SUBC("nippy"), SUBC("preach"), SUBC("magical"), SUBC("refuse"), SUBC("coast"), SUBC("aftermath"), SUBC("afterthought"), SUBC("straw"), SUBC("prick"), SUBC("chivalrous"), SUBC("next"), SUBC("bawdy"), SUBC("reject"), SUBC("yielding"), SUBC("blue"), SUBC("vessel"), SUBC("price"), SUBC("concern"), SUBC("plane"), SUBC("cent"), SUBC("hospitable"), SUBC("lopsided"), SUBC("square"), SUBC("closed"), SUBC("defeated"),
	SUBC("adamant"), SUBC("thaw"), SUBC("pot"), SUBC("plucky"), SUBC("annoyed"), SUBC("unnatural"), SUBC("shiny"), SUBC("meek"), SUBC("polite"), SUBC("texture"), SUBC("line"), SUBC("territory"), SUBC("glass"), SUBC("direction"), SUBC("haunt"), SUBC("smell"), SUBC("fact"), SUBC("fumbling"), SUBC("ragged"), SUBC("dull"), SUBC("steer"), SUBC("division"), SUBC("preserve"), SUBC("breakable"), SUBC("fetch"), SUBC("acceptable"), SUBC("file"), SUBC("happy"), SUBC("listen"), SUBC("tail"),
	SUBC("part"), SUBC("vase"), SUBC("harm"), SUBC("painful"), SUBC("live"), SUBC("stitch"), SUBC("hysterical"), SUBC("strap"), SUBC("clumsy"), SUBC("concerned"), SUBC("basket"), SUBC("art"), SUBC("fall"), SUBC("temporary"), SUBC("welcome"), SUBC("destruction"), SUBC("necessary"), SUBC("steep"), SUBC("drop"), SUBC("phobic"), SUBC("oil"), SUBC("applaud"), SUBC("waiting"), SUBC("chance"), SUBC("toothpaste"), SUBC("support"), SUBC("chubby"), SUBC("scrape"), SUBC("song"), SUBC("rock"),
	SUBC("minister"), SUBC("corn"), SUBC("weak"), SUBC("remain"), SUBC("damaging"), SUBC("demonic"), SUBC("past"), SUBC("mind"), SUBC("stone"), SUBC("minor"), SUBC("drop"), SUBC("sore"), SUBC("mere"), SUBC("mushy"), SUBC("cemetery"), SUBC("icy"), SUBC("pump"), SUBC("amazing"), SUBC("oval"), SUBC("sticks"), SUBC("escape"), SUBC("mighty"), SUBC("skin"), SUBC("friction"), SUBC("cats"), SUBC("terrify"), SUBC("divergent"), SUBC("wistful"), SUBC("camp"), SUBC("yoke"),
	SUBC("offer"), SUBC("rule"), SUBC("end"), SUBC("jellyfish"), SUBC("trick"), SUBC("general"), SUBC("circle"), SUBC("woozy"), SUBC("flash"), SUBC("miniature"), SUBC("judicious"), SUBC("auspicious"), SUBC("superficial"), SUBC("subtract"), SUBC("wrong"), SUBC("land"), SUBC("watch"), SUBC("base"), SUBC("tenuous"), SUBC("tense"), SUBC("office"), SUBC("wing"), SUBC("curved"), SUBC("book"), SUBC("fog"), SUBC("seed"), SUBC("system"), SUBC("unit"), SUBC("gun"), SUBC("hard-to-find"),
	SUBC("start"), SUBC("giraffe"), SUBC("channel"), SUBC("round"), SUBC("announce"), SUBC("twist"), SUBC("appliance"), SUBC("far"), SUBC("well-off"), SUBC("reach"), SUBC("correct"), SUBC("voice"), SUBC("party"), SUBC("lock"), SUBC("ruthless"), SUBC("hypnotic"), SUBC("trains"), SUBC("feeling"), SUBC("purple"), SUBC("space"), SUBC("thankful"), SUBC("religion"), SUBC("credit"), SUBC("potato"), SUBC("number"), SUBC("ambitious"), SUBC("halting"), SUBC("pail"), SUBC("snake"), SUBC("eight"),
	SUBC("gainful"), SUBC("angry"), SUBC("love"), SUBC("blow"), SUBC("unable"), SUBC("young"), SUBC("salt"), SUBC("grandmother"), SUBC("settle"), SUBC("sniff"), SUBC("abiding"), SUBC("incredible"), SUBC("carve"), SUBC("earthy"), SUBC("paper"), SUBC("paint"), SUBC("mate"), SUBC("heartbreaking"), SUBC("basin"), SUBC("analyse"), SUBC("war"), SUBC("stocking"), SUBC("allow"), SUBC("battle"), SUBC("rabid"), SUBC("rejoice"), SUBC("aware"), SUBC("sack"), SUBC("desk"), SUBC("youthful"),
	SUBC("cub"), SUBC("lamp"), SUBC("omniscient"), SUBC("grain"), SUBC("devilish"), SUBC("metal"), SUBC("squealing"), SUBC("attach"), SUBC("real"), SUBC("hill"), SUBC("magic"), SUBC("outstanding"), SUBC("responsible"), SUBC("silent"), SUBC("puncture"), SUBC("fresh"), SUBC("carriage"), SUBC("sail"), SUBC("windy"), SUBC("lavish"), SUBC("productive"), SUBC("pastoral"), SUBC("form"), SUBC("abject"), SUBC("honorable"), SUBC("possess"), SUBC("week"), SUBC("mint"), SUBC("placid"), SUBC("advertisement"),
	SUBC("smelly"), SUBC("clean"), SUBC("frog"), SUBC("dam"), SUBC("glistening"), SUBC("brave"), SUBC("hammer"), SUBC("believe"), SUBC("fuel"), SUBC("ocean"), SUBC("neighborly"), SUBC("awake"), SUBC("long-term"), SUBC("adorable"), SUBC("telling"), SUBC("ceaseless"), SUBC("imagine"), SUBC("answer"), SUBC("ants"), SUBC("helpless"), SUBC("tightfisted"), SUBC("gold"), SUBC("grumpy"), SUBC("handle"), SUBC("mountain"), SUBC("collect"), SUBC("bite-sized"), SUBC("cable"), SUBC("murder"), SUBC("mellow"),
	SUBC("receipt"), SUBC("muddle"), SUBC("meeting"), SUBC("scribble"), SUBC("rough"), SUBC("gleaming"), SUBC("jail"), SUBC("depend"), SUBC("permit"), SUBC("delicate"), SUBC("ethereal"), SUBC("far-flung"), SUBC("look"), SUBC("addicted"), SUBC("teeny"), SUBC("holistic"), SUBC("foolish"), SUBC("act"), SUBC("homeless"), SUBC("plug"), SUBC("various"), SUBC("electric"), SUBC("quilt"), SUBC("airport"), SUBC("apathetic"), SUBC("ink"), SUBC("tangy"), SUBC("bike"), SUBC("queue"), SUBC("door"),
	SUBC("calm"), SUBC("comb"), SUBC("perfect"), SUBC("nonstop"), SUBC("cheese"), SUBC("faded"), SUBC("wish"), SUBC("plant"), SUBC("unadvised"), SUBC("hilarious"), SUBC("rapid"), SUBC("foregoing"), SUBC("alert"), SUBC("kick"), SUBC("safe"), SUBC("letter"), SUBC("empty"), SUBC("fixed"), SUBC("busy"), SUBC("black-and-white"), SUBC("receive"), SUBC("foot"), SUBC("instruct"), SUBC("voyage"), SUBC("cream"), SUBC("pencil"), SUBC("cagey"), SUBC("nonchalant"), SUBC("handy"), SUBC("bells"),
	SUBC("abandoned"), SUBC("educated"), SUBC("fit"), SUBC("elfin"), SUBC("elastic"), SUBC("cook"), SUBC("thumb"), SUBC("three"), SUBC("sophisticated"), SUBC("class"), SUBC("attempt"), SUBC("unsightly"), SUBC("cap"), SUBC("squeeze"), SUBC("proud"), SUBC("tramp"), SUBC("maniacal"), SUBC("dashing"), SUBC("puffy"), SUBC("amused"), SUBC("screw"), SUBC("sweltering"), SUBC("moan"), SUBC("describe"), SUBC("cars"), SUBC("brake"), SUBC("purring"), SUBC("axiomatic"), SUBC("thing"), SUBC("mailbox"),
	SUBC("ruddy"), SUBC("apparel"), SUBC("coach"), SUBC("egg"), SUBC("branch"), SUBC("stick"), SUBC("fry"), SUBC("amusement"), SUBC("need"), SUBC("recondite"), SUBC("things"), SUBC("quirky"), SUBC("pie"), SUBC("perpetual"), SUBC("horrible"), SUBC("jelly"), SUBC("contain"), SUBC("narrow"), SUBC("quiet"), SUBC("satisfy"), SUBC("cellar"), SUBC("boring"), SUBC("education"), SUBC("wrestle"), SUBC("fragile"), SUBC("provide"), SUBC("effect"), SUBC("pies"), SUBC("puny"), SUBC("great"),
	SUBC("frogs"), SUBC("prepare"), SUBC("paddle"), SUBC("rabbit"), SUBC("observation"), SUBC("hands"), SUBC("crib"), SUBC("attack"), SUBC("rose"), SUBC("coherent"), SUBC("back"), SUBC("explode"), SUBC("hulking"), SUBC("cat"), SUBC("subsequent"), SUBC("tray"), SUBC("valuable"), SUBC("natural"), SUBC("cave"), SUBC("repulsive"), SUBC("harsh"), SUBC("overflow"), SUBC("dogs"), SUBC("rod"), SUBC("married"), SUBC("choke"), SUBC("deserve"), SUBC("cabbage"), SUBC("understood"), SUBC("anger"),
	SUBC("shy"), SUBC("wrathful"), SUBC("inquisitive"), SUBC("ring"), SUBC("wheel"), SUBC("face"), SUBC("arrogant"), SUBC("snakes"), SUBC("subdued"), SUBC("labored"), SUBC("float"), SUBC("request"), SUBC("victorious"), SUBC("gusty"), SUBC("yak"), SUBC("pop"), SUBC("dependent"), SUBC("double"), SUBC("rinse"), SUBC("scintillating"), SUBC("eatable"), SUBC("verse"), SUBC("transport"), SUBC("detail"), SUBC("quiet"), SUBC("enter"), SUBC("nerve"), SUBC("towering"), SUBC("needless"), SUBC("bubble"),
	SUBC("doctor"), SUBC("ruin"), SUBC("bead"), SUBC("expand"), SUBC("shop"), SUBC("tent"), SUBC("difficult"), SUBC("celery"), SUBC("judge"), SUBC("statuesque"), SUBC("abaft"), SUBC("wonderful"), SUBC("influence"), SUBC("hole"), SUBC("maid"), SUBC("sea"), SUBC("gentle"), SUBC("witty"), SUBC("even"), SUBC("trashy"), SUBC("turn"), SUBC("hateful"), SUBC("weight"), SUBC("bucket"), SUBC("tasty"), SUBC("unequal"), SUBC("fertile"), SUBC("release"), SUBC("gate"), SUBC("touch"),
	SUBC("fluffy"), SUBC("print"), SUBC("command"), SUBC("horses"), SUBC("compete"), SUBC("sassy"), SUBC("children"), SUBC("girl"), SUBC("smash"), SUBC("workable"), SUBC("key"), SUBC("balance"), SUBC("story"), SUBC("rampant"), SUBC("interfere"), SUBC("distinct"), SUBC("death"), SUBC("dinner"), SUBC("flow"), SUBC("sordid"), SUBC("oatmeal"), SUBC("used"), SUBC("need"), SUBC("limping"), SUBC("tight"), SUBC("tiny"), SUBC("pass"), SUBC("copy"), SUBC("shop"), SUBC("wonder"),
	SUBC("sidewalk"), SUBC("friend"), SUBC("hammer"), SUBC("craven"), SUBC("boil"), SUBC("immense"), SUBC("tense"), SUBC("attractive"), SUBC("squeal"), SUBC("six"), SUBC("vegetable"), SUBC("crook"), SUBC("eminent"), SUBC("injure"), SUBC("mark"), SUBC("obsequious"), SUBC("army"), SUBC("aunt"), SUBC("cake"), SUBC("first"), SUBC("goofy"), SUBC("oceanic"), SUBC("hair"), SUBC("needle"), SUBC("acidic"), SUBC("pan"), SUBC("stretch"), SUBC("digestion"), SUBC("blushing"), SUBC("bat"),
	SUBC("church"), SUBC("sharp"), SUBC("step"), SUBC("chew"), SUBC("riddle"), SUBC("sweet"), SUBC("try"), SUBC("painstaking"), SUBC("bomb"), SUBC("fluttering"), SUBC("squeamish"), SUBC("woman"), SUBC("disagreeable"), SUBC("stroke"), SUBC("legal"), SUBC("conscious"), SUBC("box"), SUBC("produce"), SUBC("synonymous"), SUBC("yam"), SUBC("glorious"), SUBC("red"), SUBC("snails"), SUBC("flower"), SUBC("taste"), SUBC("gaping"), SUBC("quickest"), SUBC("sincere"), SUBC("sulky"), SUBC("alarm"),
	SUBC("employ"), SUBC("collar"), SUBC("talk"), SUBC("box"), SUBC("toes"), SUBC("tomatoes"), SUBC("follow"), SUBC("man"), SUBC("post"), SUBC("jewel"), SUBC("panoramic"), SUBC("heady"), SUBC("way"), SUBC("beef"), SUBC("possible"), SUBC("elbow"), SUBC("man"), SUBC("trouble"), SUBC("humor"), SUBC("tire"), SUBC("strip"), SUBC("voracious"), SUBC("watch"), SUBC("old"), SUBC("blush"), SUBC("flowers"), SUBC("color"), SUBC("broad"), SUBC("remove"), SUBC("defective"),
	SUBC("wealthy"), SUBC("abortive"), SUBC("unusual"), SUBC("partner"), SUBC("faithful"), SUBC("calendar"), SUBC("descriptive"), SUBC("look"), SUBC("pour"), SUBC("knot"), SUBC("invent"), SUBC("afford"), SUBC("history"), SUBC("shade"), SUBC("wait"), SUBC("move"), SUBC("treat"), SUBC("scarecrow"), SUBC("brick"), SUBC("warm"), SUBC("mine"), SUBC("month"), SUBC("wax"), SUBC("license"), SUBC("smell"), SUBC("pack"), SUBC("throat"), SUBC("snow"), SUBC("science"), SUBC("aback"),
	SUBC("punch"), SUBC("silk"), SUBC("nappy"), SUBC("hallowed"), SUBC("trap"), SUBC("belong"), SUBC("form"), SUBC("error"), SUBC("rainy"), SUBC("innate"), SUBC("canvas"), SUBC("scene"), SUBC("avoid"), SUBC("accept"), SUBC("tie"), SUBC("upbeat"), SUBC("cakes"), SUBC("wrist"), SUBC("weary"), SUBC("wound"), SUBC("jagged"), SUBC("paltry"), SUBC("vagabond"), SUBC("miscreant"), SUBC("fade"), SUBC("money"), SUBC("turn"), SUBC("industry"), SUBC("hang"), SUBC("include"),
	SUBC("toe"), SUBC("smoke"), SUBC("silent"), SUBC("bolt"), SUBC("groan"), SUBC("launch"), SUBC("trucks"), SUBC("saw"), SUBC("ray"), SUBC("kind"), SUBC("probable"), SUBC("tug"), SUBC("sip"), SUBC("clean"), SUBC("jealous"), SUBC("abhorrent"), SUBC("shave"), SUBC("jail"), SUBC("wicked"), SUBC("exultant"), SUBC("cautious"), SUBC("behave"), SUBC("organic"), SUBC("normal"), SUBC("letters"), SUBC("tooth"), SUBC("soup"), SUBC("deer"), SUBC("greedy"), SUBC("animated"),
	SUBC("royal"), SUBC("meaty"), SUBC("insect"), SUBC("unite"), SUBC("utopian"), SUBC("cherries"), SUBC("grandfather"), SUBC("roll"), SUBC("marble"), SUBC("courageous"), SUBC("orange"), SUBC("teeth"), SUBC("tawdry"), SUBC("erect"), SUBC("respect"), SUBC("periodic"), SUBC("love"), SUBC("interest"), SUBC("twist"), SUBC("fire"), SUBC("lie"), SUBC("reason"), SUBC("badge"), SUBC("guarantee"), SUBC("scarf"), SUBC("clever"), SUBC("confess"), SUBC("crooked"), SUBC("ball"), SUBC("bright"),
	SUBC("raise"), SUBC("famous"), SUBC("volleyball"), SUBC("reaction"), SUBC("flame"), SUBC("star"), SUBC("mixed"), SUBC("move"), SUBC("change"), SUBC("travel"), SUBC("prose"), SUBC("consist"), SUBC("coil"), SUBC("support"), SUBC("rob"), SUBC("zephyr"), SUBC("bed"), SUBC("scale"), SUBC("receptive"), SUBC("encourage"), SUBC("continue"), SUBC("perform"), SUBC("serve"), SUBC("sound"), SUBC("crabby"), SUBC("strengthen"), SUBC("typical"), SUBC("measure"), SUBC("donkey"), SUBC("push"),
	SUBC("zip"), SUBC("high"), SUBC("blade"), SUBC("melt"), SUBC("fail"), SUBC("frantic"), SUBC("tub"), SUBC("pat"), SUBC("cross"), SUBC("sneeze"), SUBC("dynamic"), SUBC("distribution"), SUBC("tongue"), SUBC("jump"), SUBC("steadfast"), SUBC("number"), SUBC("modern"), SUBC("clap"), SUBC("inconclusive"), SUBC("dead"), SUBC("tested"), SUBC("rural"), SUBC("authority"), SUBC("borrow"), SUBC("search"), SUBC("rotten"), SUBC("awesome"), SUBC("last"), SUBC("heap"), SUBC("drain"),
	SUBC("pick"), SUBC("action"), SUBC("resolute"), SUBC("unfasten"), SUBC("railway"), SUBC("odd"), SUBC("macabre"), SUBC("suggestion"), SUBC("plough"), SUBC("stale"), SUBC("unkempt"), SUBC("impolite"), SUBC("impossible"), SUBC("shaky"), SUBC("nauseating"), SUBC("knotty"), SUBC("cute"), SUBC("swim"), SUBC("add"), SUBC("whole"), SUBC("laugh"), SUBC("messy"), SUBC("worm"), SUBC("plantation"), SUBC("succinct"), SUBC("change"), SUBC("quarrelsome"), SUBC("earthquake"), SUBC("wool"), SUBC("mix"),
	SUBC("little"), SUBC("detailed"), SUBC("spectacular"), SUBC("vigorous"), SUBC("symptomatic"), SUBC("engine"), SUBC("shaggy"), SUBC("cut"), SUBC("cattle"), SUBC("defiant"), SUBC("signal"), SUBC("development"), SUBC("kitty"), SUBC("scatter"), SUBC("physical"), SUBC("limit"), SUBC("mist"), SUBC("rub"), SUBC("writer"), SUBC("unarmed"), SUBC("consider"), SUBC("dazzling"), SUBC("hot"), SUBC("obscene"), SUBC("obeisant"), SUBC("hurried"), SUBC("hook"), SUBC("rabbits"), SUBC("crawl"), SUBC("profuse"),
	SUBC("tidy"), SUBC("loss"), SUBC("straight"), SUBC("bad"), SUBC("nutritious"), SUBC("protect"), SUBC("theory"), SUBC("page"), SUBC("gray"), SUBC("medical"), SUBC("skillful"), SUBC("dislike"), SUBC("imaginary"), SUBC("request"), SUBC("attend"), SUBC("winter"), SUBC("grip"), SUBC("bless"), SUBC("spooky"), SUBC("test"), SUBC("snore"), SUBC("afraid"), SUBC("mean"), SUBC("bare"), SUBC("spark"), SUBC("toothbrush"), SUBC("long"), SUBC("befitting"), SUBC("motion"), SUBC("bruise"),
	SUBC("tart"), SUBC("pipe"), SUBC("ignorant"), SUBC("transport"), SUBC("trade"), SUBC("nod"), SUBC("march"), SUBC("squash"), SUBC("rain"), SUBC("north"), SUBC("rhetorical"), SUBC("damp"), SUBC("deadpan"), SUBC("freezing"), SUBC("thundering"), SUBC("romantic"), SUBC("undress"), SUBC("lovely"), SUBC("materialistic"), SUBC("flimsy"), SUBC("discover"), SUBC("chemical"), SUBC("meddle"), SUBC("abstracted"), SUBC("pickle"), SUBC("intend"), SUBC("scrawny"), SUBC("thread"), SUBC("temper"), SUBC("equal"),
	SUBC("alleged"), SUBC("shirt"), SUBC("festive"), SUBC("profit"), SUBC("dramatic"), SUBC("roomy"), SUBC("evasive"), SUBC("scent"), SUBC("battle"), SUBC("fax"), SUBC("rainstorm"), SUBC("uncovered"), SUBC("melodic"), SUBC("stretch"), SUBC("learned"), SUBC("petite"), SUBC("idiotic"), SUBC("breezy"), SUBC("finger"), SUBC("ban"), SUBC("mass"), SUBC("clip"), SUBC("stem"), SUBC("cracker"), SUBC("separate"), SUBC("macho"), SUBC("connect"), SUBC("observe"), SUBC("heavy"), SUBC("guess"),
	SUBC("ugliest"), SUBC("stay"), SUBC("pet"), SUBC("tick"), SUBC("abusive"), SUBC("bustling"), SUBC("actor"), SUBC("easy"), SUBC("spiky"), SUBC("pump"), SUBC("surround"), SUBC("show"), SUBC("business"), SUBC("scandalous"), SUBC("volcano"), SUBC("spare"), SUBC("lamentable"), SUBC("second-hand"), SUBC("rich"), SUBC("degree"), SUBC("market"), SUBC("wriggle"), SUBC("queen"), SUBC("machine"), SUBC("small"), SUBC("seashore"), SUBC("fire"), SUBC("spring"), SUBC("chickens"), SUBC("back"),
	SUBC("rock"), SUBC("deeply"), SUBC("lunch"), SUBC("flight"), SUBC("heal"), SUBC("accessible"), SUBC("charming"), SUBC("glamorous"), SUBC("statement"), SUBC("tin"), SUBC("erratic"), SUBC("cycle"), SUBC("brawny"), SUBC("disillusioned"), SUBC("capable"), SUBC("shivering"), SUBC("vague"), SUBC("glow"), SUBC("educate"), SUBC("leg"), SUBC("momentous"), SUBC("sock"), SUBC("absent"), SUBC("complex"), SUBC("wacky"), SUBC("massive"), SUBC("sudden"), SUBC("doll"), SUBC("soothe"), SUBC("secret"),
	SUBC("whisper"), SUBC("loud"), SUBC("tasteful"), SUBC("faulty"), SUBC("weigh"), SUBC("annoying"), SUBC("wretched"), SUBC("spot"), SUBC("marry"), SUBC("yard"), SUBC("whimsical"), SUBC("tour"), SUBC("raspy"), SUBC("spot"), SUBC("rail"), SUBC("anxious"), SUBC("insurance"), SUBC("itch"), SUBC("delight"), SUBC("lowly"), SUBC("claim"), SUBC("bee"), SUBC("arrive"), SUBC("aspiring"), SUBC("purpose"), SUBC("direful"), SUBC("ludicrous"), SUBC("tacit"), SUBC("rate"), SUBC("agreeable"),
	SUBC("knot"), SUBC("sleep"), SUBC("fireman"), SUBC("internal"), SUBC("wide-eyed"), SUBC("glove"), SUBC("dad"), SUBC("blind"), SUBC("fallacious"), SUBC("tedious"), SUBC("familiar"), SUBC("save"), SUBC("pleasure"), SUBC("beautiful"), SUBC("square"), SUBC("taste"), SUBC("empty"), SUBC("debonair"), SUBC("bikes"), SUBC("legs"), SUBC("balance"), SUBC("irritate"), SUBC("apologise"), SUBC("lackadaisical"), SUBC("eggs"), SUBC("fix"), SUBC("dispensable"), SUBC("hunt"), SUBC("quartz"), SUBC("group"),
	SUBC("literate"), SUBC("vengeful"), SUBC("earth"), SUBC("control"), SUBC("cover"), SUBC("drunk"), SUBC("reminiscent"), SUBC("ticket"), SUBC("cheer"), SUBC("government"), SUBC("stop"), SUBC("public"), SUBC("boast"), SUBC("hanging"), SUBC("label"), SUBC("brief"), SUBC("order"), SUBC("encouraging"), SUBC("enthusiastic"), SUBC("table"), SUBC("reduce"), SUBC("side"), SUBC("hesitant"), SUBC("wave"), SUBC("cactus"), SUBC("spade"), SUBC("mysterious"), SUBC("guttural"), SUBC("calculator"), SUBC("rice"),
	SUBC("dusty"), SUBC("overwrought"), SUBC("nation"), SUBC("blink"), SUBC("alcoholic"), SUBC("care"), SUBC("bat"), SUBC("cheerful"), SUBC("sticky"), SUBC("exotic"), SUBC("slippery"), SUBC("spell"), SUBC("promise"), SUBC("ashamed"), SUBC("ignore"), SUBC("colossal"), SUBC("moldy"), SUBC("stomach"), SUBC("hop"), SUBC("overt"), SUBC("umbrella"), SUBC("scream"), SUBC("callous"), SUBC("tiresome"), SUBC("discovery"), SUBC("poison"), SUBC("mountainous"), SUBC("scattered"), SUBC("flower"), SUBC("quarter"),
	SUBC("well-groomed"), SUBC("carpenter"), SUBC("invention"), SUBC("border"), SUBC("roll"), SUBC("crayon"), SUBC("racial"), SUBC("groovy"), SUBC("spray"), SUBC("bashful"), SUBC("nifty"), SUBC("replace"), SUBC("leather"), SUBC("sofa"), SUBC("expensive"), SUBC("aloof"), SUBC("tame"), SUBC("beginner"), SUBC("count"), SUBC("crow"), SUBC("repeat"), SUBC("field"), SUBC("found"), SUBC("present"), SUBC("tap"), SUBC("screw"), SUBC("soak"), SUBC("accidental"), SUBC("wide"), SUBC("chunky"),
	SUBC("illustrious"), SUBC("simple"), SUBC("robust"), SUBC("writing"), SUBC("land"), SUBC("approval"), SUBC("mother"), SUBC("jazzy"), SUBC("vast"), SUBC("inexpensive"), SUBC("harmonious"), SUBC("swift"), SUBC("silver"), SUBC("savory"), SUBC("afternoon"), SUBC("spoil"), SUBC("cloth"), SUBC("agreement"), SUBC("drum"), SUBC("unwieldy"), SUBC("amuck"), SUBC("language"), SUBC("mindless"), SUBC("plant"), SUBC("godly"), SUBC("alert"), SUBC("fantastic"), SUBC("disapprove"), SUBC("punish"), SUBC("four"),
	SUBC("belief"), SUBC("turkey"), SUBC("enchanting"), SUBC("fool"), SUBC("fearful"), SUBC("absorbing"), SUBC("hapless"), SUBC("tiger"), SUBC("remarkable"), SUBC("nutty"), SUBC("orange"), SUBC("aromatic"), SUBC("wilderness"), SUBC("cast"), SUBC("bore"), SUBC("deliver"), SUBC("lethal"), SUBC("word"), SUBC("porter"), SUBC("thunder"), SUBC("ill"), SUBC("unknown"), SUBC("dog"), SUBC("buzz"), SUBC("chop"), SUBC("damaged"), SUBC("hot"), SUBC("laugh"), SUBC("ladybug"), SUBC("multiply"),
	SUBC("grape"), SUBC("explain"), SUBC("jam"), SUBC("roof"), SUBC("example"), SUBC("seemly"), SUBC("smoke"), SUBC("worried"), SUBC("sponge"), SUBC("crush"), SUBC("obedient"), SUBC("strong"), SUBC("seat"), SUBC("work"), SUBC("cowardly"), SUBC("account"), SUBC("tow"), SUBC("extra-small"), SUBC("drag"), SUBC("pine"), SUBC("wander"), SUBC("cumbersome"), SUBC("picayune"), SUBC("salty"), SUBC("desire"), SUBC("ill-fated"), SUBC("scorch"), SUBC("treatment"), SUBC("skip"), SUBC("unused"),
	SUBC("growth"), SUBC("wasteful"), SUBC("deafening"), SUBC("uptight"), SUBC("premium"), SUBC("card"), SUBC("observant"), SUBC("obnoxious"), SUBC("pigs"), SUBC("talk"), SUBC("astonishing"), SUBC("lettuce"), SUBC("start"), SUBC("trip"), SUBC("activity"), SUBC("attraction"), SUBC("jumbled"), SUBC("wall"), SUBC("knowing"), SUBC("ordinary"), SUBC("domineering"), SUBC("garrulous"), SUBC("frightening"), SUBC("lively"), SUBC("unlock"), SUBC("match"), SUBC("shape"), SUBC("splendid"), SUBC("wrap"), SUBC("wholesale"),
	SUBC("ask"), SUBC("concentrate"), SUBC("thin"), SUBC("psychotic"), SUBC("wiry"), SUBC("measly"), SUBC("thirsty"), SUBC("dry"), SUBC("truculent"), SUBC("like"), SUBC("scary"), SUBC("monkey"), SUBC("spiteful"), SUBC("summer"), SUBC("obsolete"), SUBC("pretend"), SUBC("room"), SUBC("run"), SUBC("lyrical"), SUBC("position"), SUBC("grieving"), SUBC("husky"), SUBC("harmony"), SUBC("sheet"), SUBC("rain"), SUBC("jolly"), SUBC("offer"), SUBC("snow"), SUBC("excuse"), SUBC("lacking"),
	SUBC("gabby"), SUBC("successful"), SUBC("healthy"), SUBC("regret"), SUBC("tremble"), SUBC("lace"), SUBC("stupid"), SUBC("flaky"), SUBC("wanting"), SUBC("experience"), SUBC("loose"), SUBC("wry"), SUBC("colorful"), SUBC("hideous"), SUBC("liquid"), SUBC("absurd"), SUBC("zoom"), SUBC("two"), SUBC("steam"), SUBC("warlike"), SUBC("grab"), SUBC("heat"), SUBC("basketball"), SUBC("swanky"), SUBC("birds"), SUBC("five"), SUBC("breath"), SUBC("calculating"), SUBC("approve"), SUBC("dangerous"),
	SUBC("club"), SUBC("giants"), SUBC("uncle"), SUBC("downtown"), SUBC("extend"), SUBC("dusty"), SUBC("jobless"), SUBC("impress"), SUBC("press"), SUBC("grandiose"), SUBC("jam"), SUBC("useless"), SUBC("female"), SUBC("board"), SUBC("doubt"), SUBC("report"), SUBC("sound"), SUBC("mourn"), SUBC("flagrant"), SUBC("sigh"), SUBC("boot"), SUBC("suspend"), SUBC("entertaining"), SUBC("precious"), SUBC("efficacious"), SUBC("tame"), SUBC("old-fashioned"), SUBC("spicy"), SUBC("quicksand"), SUBC("vulgar"),
	SUBC("house"), SUBC("jaded"), SUBC("fine"), SUBC("roasted"), SUBC("selection"), SUBC("near"), SUBC("curious"), SUBC("caring"), SUBC("detect"), SUBC("zoo"),
	SUBC("100"), SUBC("101"), SUBC("102"), SUBC("103"), SUBC("104"), SUBC("105"), SUBC("106"), SUBC("107"), SUBC("108"), SUBC("109"), SUBC("110"), SUBC("111"), SUBC("112"), SUBC("113"), SUBC("114"), SUBC("115"), SUBC("116"), SUBC("117"), SUBC("118"), SUBC("119"), SUBC("120"), SUBC("121"), SUBC("122"), SUBC("123"), SUBC("124"), SUBC("125"), SUBC("126"), SUBC("127"), SUBC("128"), SUBC("129"), SUBC("130"),
	SUBC("131"), SUBC("132"), SUBC("133"), SUBC("134"), SUBC("135"), SUBC("136"), SUBC("137"), SUBC("138"), SUBC("139"), SUBC("140"), SUBC("141"), SUBC("142"), SUBC("143"), SUBC("144"), SUBC("145"), SUBC("146"), SUBC("147"), SUBC("148"), SUBC("149"), SUBC("150"), SUBC("151"), SUBC("152"), SUBC("153"), SUBC("154"), SUBC("155"), SUBC("156"), SUBC("157"), SUBC("158"), SUBC("159"), SUBC("160"), SUBC("161"),
	SUBC("162"), SUBC("163"), SUBC("164"), SUBC("165"), SUBC("166"), SUBC("167"), SUBC("168"), SUBC("169"), SUBC("170"), SUBC("171"), SUBC("172"), SUBC("173"), SUBC("174"), SUBC("175"), SUBC("176"), SUBC("177"), SUBC("178"), SUBC("179"), SUBC("180"), SUBC("181"), SUBC("182"), SUBC("183"), SUBC("184"), SUBC("185"), SUBC("186"), SUBC("187"), SUBC("188"), SUBC("189"), SUBC("190"), SUBC("191"), SUBC("192"),
	SUBC("193"), SUBC("194"), SUBC("195"), SUBC("196"), SUBC("197"), SUBC("198"), SUBC("199"), SUBC("200"), SUBC("201"), SUBC("202"), SUBC("203"), SUBC("204"), SUBC("205"), SUBC("206"), SUBC("207"), SUBC("208"), SUBC("209"), SUBC("210"), SUBC("211"), SUBC("212"), SUBC("213"), SUBC("214"), SUBC("215"), SUBC("216"), SUBC("217"), SUBC("218"), SUBC("219"), SUBC("220"), SUBC("221"), SUBC("222"), SUBC("223"),
	SUBC("224"), SUBC("225"), SUBC("226"), SUBC("227"), SUBC("228"), SUBC("229"), SUBC("230"), SUBC("231"), SUBC("232"), SUBC("233"), SUBC("234"), SUBC("235"), SUBC("236"), SUBC("237"), SUBC("238"), SUBC("239"), SUBC("240"), SUBC("241"), SUBC("242"), SUBC("243"), SUBC("244"), SUBC("245"), SUBC("246"), SUBC("247"), SUBC("248"), SUBC("249"), SUBC("250"), SUBC("251"), SUBC("252"), SUBC("253"), SUBC("254"),
	SUBC("255"), SUBC("256"), SUBC("257"), SUBC("258"), SUBC("259"), SUBC("260"), SUBC("261"), SUBC("262"), SUBC("263"), SUBC("264"), SUBC("265"), SUBC("266"), SUBC("267"), SUBC("268"), SUBC("269"), SUBC("270"), SUBC("271"), SUBC("272"), SUBC("273"), SUBC("274"), SUBC("275"), SUBC("276"), SUBC("277"), SUBC("278"), SUBC("279"), SUBC("280"), SUBC("281"), SUBC("282"), SUBC("283"), SUBC("284"), SUBC("285"),
	SUBC("286"), SUBC("287"), SUBC("288"), SUBC("289"), SUBC("290"), SUBC("291"), SUBC("292"), SUBC("293"), SUBC("294"), SUBC("295"), SUBC("296"), SUBC("297"), SUBC("298"), SUBC("299"), SUBC("300"), SUBC("301"), SUBC("302"), SUBC("303"), SUBC("304"), SUBC("305"), SUBC("306"), SUBC("307"), SUBC("308"), SUBC("309"), SUBC("310"), SUBC("311"), SUBC("312"), SUBC("313"), SUBC("314"), SUBC("315"), SUBC("316"),
	SUBC("317"), SUBC("318"), SUBC("319"), SUBC("320"), SUBC("321"), SUBC("322"), SUBC("323"), SUBC("324"), SUBC("325"), SUBC("326"), SUBC("327"), SUBC("328"), SUBC("329"), SUBC("330"), SUBC("331"), SUBC("332"), SUBC("333"), SUBC("334"), SUBC("335"), SUBC("336"), SUBC("337"), SUBC("338"), SUBC("339"), SUBC("340"), SUBC("341"), SUBC("342"), SUBC("343"), SUBC("344"), SUBC("345"), SUBC("346"), SUBC("347"),
	SUBC("348"), SUBC("349"), SUBC("350"), SUBC("351"), SUBC("352"), SUBC("353"), SUBC("354"), SUBC("355"), SUBC("356"), SUBC("357"), SUBC("358"), SUBC("359"), SUBC("360"), SUBC("361"), SUBC("362"), SUBC("363"), SUBC("364"), SUBC("365"), SUBC("366"), SUBC("367"), SUBC("368"), SUBC("369"), SUBC("370"), SUBC("371"), SUBC("372"), SUBC("373"), SUBC("374"), SUBC("375"), SUBC("376"), SUBC("377"), SUBC("378"),
	SUBC("379"), SUBC("380"), SUBC("381"), SUBC("382"), SUBC("383"), SUBC("384"), SUBC("385"), SUBC("386"), SUBC("387"), SUBC("388"), SUBC("389"), SUBC("390"), SUBC("391"), SUBC("392"), SUBC("393"), SUBC("394"), SUBC("395"), SUBC("396"), SUBC("397"), SUBC("398"), SUBC("399"), SUBC("400"), SUBC("401"), SUBC("402"), SUBC("403"), SUBC("404"), SUBC("405"), SUBC("406"), SUBC("407"), SUBC("408"), SUBC("409"),
	SUBC("410"), SUBC("411"), SUBC("412"), SUBC("413"), SUBC("414"), SUBC("415"), SUBC("416"), SUBC("417"), SUBC("418"), SUBC("419"), SUBC("420"), SUBC("421"), SUBC("422"), SUBC("423"), SUBC("424"), SUBC("425"), SUBC("426"), SUBC("427"), SUBC("428"), SUBC("429"), SUBC("430"), SUBC("431"), SUBC("432"), SUBC("433"), SUBC("434"), SUBC("435"), SUBC("436"), SUBC("437"), SUBC("438"), SUBC("439"), SUBC("440"),
	SUBC("441"), SUBC("442"), SUBC("443"), SUBC("444"), SUBC("445"), SUBC("446"), SUBC("447"), SUBC("448"), SUBC("449"), SUBC("450"), SUBC("451"), SUBC("452"), SUBC("453"), SUBC("454"), SUBC("455"), SUBC("456"), SUBC("457"), SUBC("458"), SUBC("459"), SUBC("460"), SUBC("461"), SUBC("462"), SUBC("463"), SUBC("464"), SUBC("465"), SUBC("466"), SUBC("467"), SUBC("468"), SUBC("469"), SUBC("470"), SUBC("471"),
	SUBC("472"), SUBC("473"), SUBC("474"), SUBC("475"), SUBC("476"), SUBC("477"), SUBC("478"), SUBC("479"), SUBC("480"), SUBC("481"), SUBC("482"), SUBC("483"), SUBC("484"), SUBC("485"), SUBC("486"), SUBC("487"), SUBC("488"), SUBC("489"), SUBC("490"), SUBC("491"), SUBC("492"), SUBC("493"), SUBC("494"), SUBC("495"), SUBC("496"), SUBC("497"), SUBC("498"), SUBC("499"), SUBC("500"), SUBC("501"), SUBC("502"),
	SUBC("503"), SUBC("504"), SUBC("505"), SUBC("506"), SUBC("507"), SUBC("508"), SUBC("509"), SUBC("510"), SUBC("511"), SUBC("512"), SUBC("513"), SUBC("514"), SUBC("515"), SUBC("516"), SUBC("517"), SUBC("518"), SUBC("519"), SUBC("520"), SUBC("521"), SUBC("522"), SUBC("523"), SUBC("524"), SUBC("525"), SUBC("526"), SUBC("527"), SUBC("528"), SUBC("529"), SUBC("530"), SUBC("531"), SUBC("532"), SUBC("533"),
	SUBC("534"), SUBC("535"), SUBC("536"), SUBC("537"), SUBC("538"), SUBC("539"), SUBC("540"), SUBC("541"), SUBC("542"), SUBC("543"), SUBC("544"), SUBC("545"), SUBC("546"), SUBC("547"), SUBC("548"), SUBC("549"), SUBC("550"), SUBC("551"), SUBC("552"), SUBC("553"), SUBC("554"), SUBC("555"), SUBC("556"), SUBC("557"), SUBC("558"), SUBC("559"), SUBC("560"), SUBC("561"), SUBC("562"), SUBC("563"), SUBC("564"),
	SUBC("565"), SUBC("566"), SUBC("567"), SUBC("568"), SUBC("569"), SUBC("570"), SUBC("571"), SUBC("572"), SUBC("573"), SUBC("574"), SUBC("575"), SUBC("576"), SUBC("577"), SUBC("578"), SUBC("579"), SUBC("580"), SUBC("581"), SUBC("582"), SUBC("583"), SUBC("584"), SUBC("585"), SUBC("586"), SUBC("587"), SUBC("588"), SUBC("589"), SUBC("590"), SUBC("591"), SUBC("592"), SUBC("593"), SUBC("594"), SUBC("595"),
	SUBC("596"), SUBC("597"), SUBC("598"), SUBC("599"), SUBC("600"), SUBC("601"), SUBC("602"), SUBC("603"), SUBC("604"), SUBC("605"), SUBC("606"), SUBC("607"), SUBC("608"), SUBC("609"), SUBC("610"), SUBC("611"), SUBC("612"), SUBC("613"), SUBC("614"), SUBC("615"), SUBC("616"), SUBC("617"), SUBC("618"), SUBC("619"), SUBC("620"), SUBC("621"), SUBC("622"), SUBC("623"), SUBC("624"), SUBC("625"), SUBC("626"),
	SUBC("627"), SUBC("628"), SUBC("629"), SUBC("630"), SUBC("631"), SUBC("632"), SUBC("633"), SUBC("634"), SUBC("635"), SUBC("636"), SUBC("637"), SUBC("638"), SUBC("639"), SUBC("640"), SUBC("641"), SUBC("642"), SUBC("643"), SUBC("644"), SUBC("645"), SUBC("646"), SUBC("647"), SUBC("648"), SUBC("649"), SUBC("650"), SUBC("651"), SUBC("652"), SUBC("653"), SUBC("654"), SUBC("655"), SUBC("656"), SUBC("657"),
	SUBC("658"), SUBC("659"), SUBC("660"), SUBC("661"), SUBC("662"), SUBC("663"), SUBC("664"), SUBC("665"), SUBC("666"), SUBC("667"), SUBC("668"), SUBC("669"), SUBC("670"), SUBC("671"), SUBC("672"), SUBC("673"), SUBC("674"), SUBC("675"), SUBC("676"), SUBC("677"), SUBC("678"), SUBC("679"), SUBC("680"), SUBC("681"), SUBC("682"), SUBC("683"), SUBC("684"), SUBC("685"), SUBC("686"), SUBC("687"), SUBC("688"),
	SUBC("689"), SUBC("690"), SUBC("691"), SUBC("692"), SUBC("693"), SUBC("694"), SUBC("695"), SUBC("696"), SUBC("697"), SUBC("698"), SUBC("699"), SUBC("700"), SUBC("701"), SUBC("702"), SUBC("703"), SUBC("704"), SUBC("705"), SUBC("706"), SUBC("707"), SUBC("708"), SUBC("709"), SUBC("710"), SUBC("711"), SUBC("712"), SUBC("713"), SUBC("714"), SUBC("715"), SUBC("716"), SUBC("717"), SUBC("718"), SUBC("719"),
	SUBC("720"), SUBC("721"), SUBC("722"), SUBC("723"), SUBC("724"), SUBC("725"), SUBC("726"), SUBC("727"), SUBC("728"), SUBC("729"), SUBC("730"), SUBC("731"), SUBC("732"), SUBC("733"), SUBC("734"), SUBC("735"), SUBC("736"), SUBC("737"), SUBC("738"), SUBC("739"), SUBC("740"), SUBC("741"), SUBC("742"), SUBC("743"), SUBC("744"), SUBC("745"), SUBC("746"), SUBC("747"), SUBC("748"), SUBC("749"), SUBC("750"),
	SUBC("751"), SUBC("752"), SUBC("753"), SUBC("754"), SUBC("755"), SUBC("756"), SUBC("757"), SUBC("758"), SUBC("759"), SUBC("760"), SUBC("761"), SUBC("762"), SUBC("763"), SUBC("764"), SUBC("765"), SUBC("766"), SUBC("767"), SUBC("768"), SUBC("769"), SUBC("770"), SUBC("771"), SUBC("772"), SUBC("773"), SUBC("774"), SUBC("775"), SUBC("776"), SUBC("777"), SUBC("778"), SUBC("779"), SUBC("780"), SUBC("781"),
	SUBC("782"), SUBC("783"), SUBC("784"), SUBC("785"), SUBC("786"), SUBC("787"), SUBC("788"), SUBC("789"), SUBC("790"), SUBC("791"), SUBC("792"), SUBC("793"), SUBC("794"), SUBC("795"), SUBC("796"), SUBC("797"), SUBC("798"), SUBC("799"), SUBC("800"), SUBC("801"), SUBC("802"), SUBC("803"), SUBC("804"), SUBC("805"), SUBC("806"), SUBC("807"), SUBC("808"), SUBC("809"), SUBC("810"), SUBC("811"), SUBC("812"),
	SUBC("813"), SUBC("814"), SUBC("815"), SUBC("816"), SUBC("817"), SUBC("818"), SUBC("819"), SUBC("820"), SUBC("821"), SUBC("822"), SUBC("823"), SUBC("824"), SUBC("825"), SUBC("826"), SUBC("827"), SUBC("828"), SUBC("829"), SUBC("830"), SUBC("831"), SUBC("832"), SUBC("833"), SUBC("834"), SUBC("835"), SUBC("836"), SUBC("837"), SUBC("838"), SUBC("839"), SUBC("840"), SUBC("841"), SUBC("842"), SUBC("843"),
	SUBC("844"), SUBC("845"), SUBC("846"), SUBC("847"), SUBC("848"), SUBC("849"), SUBC("850"), SUBC("851"), SUBC("852"), SUBC("853"), SUBC("854"), SUBC("855"), SUBC("856"), SUBC("857"), SUBC("858"), SUBC("859"), SUBC("860"), SUBC("861"), SUBC("862"), SUBC("863"), SUBC("864"), SUBC("865"), SUBC("866"), SUBC("867"), SUBC("868"), SUBC("869"), SUBC("870"), SUBC("871"), SUBC("872"), SUBC("873"), SUBC("874"),
	SUBC("875"), SUBC("876"), SUBC("877"), SUBC("878"), SUBC("879"), SUBC("880"), SUBC("881"), SUBC("882"), SUBC("883"), SUBC("884"), SUBC("885"), SUBC("886"), SUBC("887"), SUBC("888"), SUBC("889"), SUBC("890"), SUBC("891"), SUBC("892"), SUBC("893"), SUBC("894"), SUBC("895"), SUBC("896"), SUBC("897"), SUBC("898"), SUBC("899"), SUBC("900"), SUBC("901"), SUBC("902"), SUBC("903"), SUBC("904"), SUBC("905"),
	SUBC("906"), SUBC("907"), SUBC("908"), SUBC("909"), SUBC("910"), SUBC("911"), SUBC("912"), SUBC("913"), SUBC("914"), SUBC("915"), SUBC("916"), SUBC("917"), SUBC("918"), SUBC("919"), SUBC("920"), SUBC("921"), SUBC("922"), SUBC("923"), SUBC("924"), SUBC("925"), SUBC("926"), SUBC("927"), SUBC("928"), SUBC("929"), SUBC("930"), SUBC("931"), SUBC("932"), SUBC("933"), SUBC("934"), SUBC("935"), SUBC("936"),
	SUBC("937"), SUBC("938"), SUBC("939"), SUBC("940"), SUBC("941"), SUBC("942"), SUBC("943"), SUBC("944"), SUBC("945"), SUBC("946"), SUBC("947"), SUBC("948"), SUBC("949"), SUBC("950"), SUBC("951"), SUBC("952"), SUBC("953"), SUBC("954"), SUBC("955"), SUBC("956"), SUBC("957"), SUBC("958"), SUBC("959"), SUBC("960"), SUBC("961"), SUBC("962"), SUBC("963"), SUBC("964"), SUBC("965"), SUBC("966"), SUBC("967"),
	SUBC("968"), SUBC("969"), SUBC("970"), SUBC("971"), SUBC("972"), SUBC("973"), SUBC("974"), SUBC("975"), SUBC("976"), SUBC("977"), SUBC("978"), SUBC("979"), SUBC("980"), SUBC("981"), SUBC("982"), SUBC("983"), SUBC("984"), SUBC("985"), SUBC("986"), SUBC("987"), SUBC("988"), SUBC("989"), SUBC("990"), SUBC("991"), SUBC("992"), SUBC("993"), SUBC("994"), SUBC("995"), SUBC("996"), SUBC("997"), SUBC("998"),
	SUBC("999")
};

#define HASH_FUNCTION	ft_djb2

// #define HASH_FUNCTION	test_h
uint32_t			test_h(t_sub s)
{
	uint32_t			h;
	int				i;

	i = -1;
	h = s.length;
	while (++i < s.length)
		h = (h << 2) + s.str[i];
	return (h);
}

// #define HASH_FUNCTION	test_h_ignorecase
uint32_t			test_h_ignorecase(t_sub s)
{
	uint32_t			h;
	int				i;

	i = -1;
	h = s.length;
	while (++i < s.length)
		h = (h << 2) + LOWER(s.str[i]);
	return (h);
}

// #define HASH_FUNCTION	test_bad_h
uint32_t			test_bad_h(t_sub s)
{
	uint32_t			h;
	int				i;

	i = -1;
	h = s.length;
	while (++i < s.length)
		h = h * s.str[i] + h;
	return (h);
}

static uint64_t	test_add(t_hmap *map, int count)
{
	int				i;
	uint64_t			t;

	t = ft_clock(0);
	for (i = 0; i < count; ++i)
	{
		ft_hmapputp(map, g_test_keys[rand() % G_ARRAY_LEN(g_test_keys)],
			(void*)(g_test_keys + (rand() % G_ARRAY_LEN(g_test_keys))));
	}
	t = ft_clock(t);
	ft_printf("Added %d: size:%d; time:%lld\n", count, map->size, t);
	return (t);
}

static void		print_hmap_debug(t_hmap *map)
{
	int				i;
	int				len;
	int				total_len;
	int				average;
	int				average_plus;
	int				average_less;
	int				min;
	int				max;
	t_h				*tmp;

	PS("hmap:");
	total_len = 0;
	i = -1;
	average = 0;
	while (++i < map->alloc_size)
	{
		len = 0;
		tmp = map->data[i];
		while (tmp != NULL)
		{
			len++;
			tmp = tmp->next;
		}
		average += len;
		total_len += len;
		P(" %d", len);
	}
	average /= map->alloc_size;
	average_plus = 0;
	average_less = 0;
	min = total_len;
	max = 0;
	i = -1;
	while (++i < map->alloc_size)
	{
		len = 0;
		tmp = map->data[i];
		while (tmp != NULL)
		{
			len++;
			tmp = tmp->next;
		}
		if (len > max)
			max = len;
		if (len < min)
			min = len;
		if (len < average)
			average_less++;
		else if (len > average)
			average_plus++;
	}
	P(";\n\ttotal: %d; size: %d; average: %d; -: %d; +: %d; min: %d; max: %d",
		total_len, map->alloc_size, average, average_less, average_plus, min, max);
	NL;
	if (total_len != map->size)
		P("Error: total_len != size (%d, %d)", total_len, map->size), NL;
}

static uint64_t	test_get(t_hmap *map, int count)
{
	int				i;
	int				found;
	uint64_t			t;

	found = 0;
	t = ft_clock(0);
	for (i = 0; i < count; ++i)
	{
		if (ft_hmapget(map, g_test_keys[rand() % G_ARRAY_LEN(g_test_keys)]) != NULL)
			found++;
	}
	t = ft_clock(t);
	ft_printf("Get %d: found:%d; time:%lld\n", count, found, t);
	return (t);
}

static uint64_t	test_add_all(t_hmap *map)
{
	int				i;
	uint64_t			t;

	i = -1;
	t = ft_clock(0);
	while (++i < G_ARRAY_LEN(g_test_keys))
		ft_hmapput(map, g_test_keys[i], &(int){5}, sizeof(int));
	t = ft_clock(t);
	ft_printf("Add all (size: %d)\n", map->size);
	return (t);
}

int				main(int argc, char **argv)
{
	t_hmap			*map;
	uint64_t			t;
	int				alloc_size;

	alloc_size = (argc > 1) ? ft_atoi(argv[1]) : 50;
	srand(ft_clock(0));
	map = ft_hmapnew(alloc_size, &HASH_FUNCTION);
	ft_printf("Start test: alloc_size:%d\n", map->alloc_size);
	print_hmap_debug(map);
	t = test_add(map, 20);
	print_hmap_debug(map);
	t += test_add(map, 200);
	print_hmap_debug(map);
	t += test_add(map, 1000);
	t += test_add(map, 20);
	t += test_add(map, 200);
	t += test_add(map, 2000);
	t += test_add(map, 20000);
	t += test_add(map, 20000);
	t += test_add(map, 20000);
	print_hmap_debug(map);
	ft_printf("Total time: %lld\n", t);
	t = test_get(map, 5);
	t += test_get(map, 20);
	t += test_get(map, 200);
	t += test_get(map, G_ARRAY_LEN(g_test_keys));
	ft_printf("Total time: %lld\n", t);
	print_hmap_debug(map);
	t = test_add_all(map);
	ft_printf("Total time: %lld\n", t);
	print_hmap_debug(map);
	return (0);
}
